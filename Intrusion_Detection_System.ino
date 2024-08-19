#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>
// WiFi
const char *ssid = ""; // Enter your WiFi name
const char *password = ""; // Enter WiFi password
// MQTT Broker
const char *mqtt_broker = "broker.hivemq.com";
const char *topic = "esp8266/IDS";
const char *mqtt_username = ""; //enter your mqtt server username
const char *mqtt_password = ""; //enter your mqtt server password
const int mqtt_port = 1883;
WiFiClient espClient;
PubSubClient client(espClient);
int sensor = D7; // Digital pin D7
const int trigPin = D6;
const int echoPin = D5;
const int buzzer = D0;
//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;
int distanceFeet;
void setup() {
Serial.begin(115200);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(sensor, INPUT); // declare sensor as input
pinMode(buzzer, OUTPUT);
// connecting to a WiFi network
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.println("Connecting to WiFi..");
}
Serial.println("Connected to the WiFi network");
//connecting to a mqtt broker
client.setServer(mqtt_broker, mqtt_port);
client.setCallback(callback);
connectToMqttBroker();
}
void callback(char *topic, byte *payload, unsigned int length) {
Serial.print("Message arrived in topic: ");
Serial.println(topic);
Serial.print("Message:");
for (int i = 0; i < length; i++) {
Serial.print((char) payload[i]);
}
Serial.println();
Serial.println("-----------------------");
}
void connectToMqttBroker() {
while (!client.connected()) {
if (client.connect("NodeMCUClient", mqtt_username, mqtt_password)) {
Serial.println("Connected to MQTT Broker");
client.subscribe("NodeMCU/Status");
} else {
Serial.print("MQTT Connection Failed, rc=");
Serial.println(client.state());
Serial.println("Retrying in 5 seconds...");
delay(5000); }
}
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculate the distance
distanceCm = duration * SOUND_VELOCITY/2;
// Convert to inches
distanceInch = distanceCm * CM_TO_INCH;
// Distance in feet
distanceFeet = distanceInch/12;
// Prints the distance on the Serial Monitor
Serial.print("Distance (cm): ");
Serial.println(distanceCm);
Serial.print("Distance (inch): ");
Serial.println(distanceInch);
//mqtt publish
//JSON
Serial.println(client.connected());
if(!client.connected()){
connectToMqttBroker();
}
client.loop();
DynamicJsonDocument jsonDoc(256);
jsonDoc["DistanceCm"] = distanceCm;
jsonDoc["DistanceIn"] = distanceInch;
jsonDoc["DistanceFeet"] = distanceFeet;
String jsonString;
serializeJson(jsonDoc, jsonString);
client.publish("esp8266/IDS", jsonString.c_str());
long state = digitalRead(sensor);
if(state == HIGH)
{
Serial.println("Motion detected!");
delay(100);
}
else
{
Serial.println("Motion absent!");
delay(100);
}
if(distanceCm<=30&&state==HIGH)
{
client.publish(topic, "Intruder Alert!!!");
jsonDoc["Intruder!!!!"];
digitalWrite(buzzer, HIGH);
delay(5000);
digitalWrite(buzzer, LOW);
}
else if(distanceCm<=50&&state==HIGH)
{
client.publish(topic,"Someone is in the Area!!");
delay(3000);
}
else if(distanceCm<=70&&state==HIGH)
{
client.publish(topic,"Someone is nearby!!");
delay(2000);
}
client.loop();
delay(200);