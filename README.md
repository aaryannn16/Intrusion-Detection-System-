# Intrusion-Detection-System-
# Project Summary 
The "Home Intrusion Detection System Using Internet of Things" 
project aims to create a robust and intelligent security solution that 
leverages the power of IoT technology to enhance home security and 
provide real-time monitoring against unauthorized access and intrusions. 
The system employs a network of interconnected smart devices and 
sensors strategically placed around the home to detect, notify, and even 
deter potential intruders. 
Key Components and Features: 
Smart Sensors: Various types of sensors such as motion sensors, 
door/window contact sensors, and glass-break detectors are strategically 
installed throughout the home. These sensors constantly monitor the 
environment for any unusual activities. 
IoT Hub: An IoT hub or gateway serves as the central communication 
point for all connected devices. It aggregates data from sensors and 
facilitates seamless communication between the devices and the central 
control unit. 
Central Control Unit: A centralized control unit processes the data 
received from sensors, analyzes it using machine learning algorithms or 
rule-based systems, and makes decisions regarding potential intrusion 
events. This unit may reside on a dedicated hardware device or in the 
cloud. 
Real-time Notifications: In the event of suspicious activities or breaches, 
the system sends instant notifications to the homeowners' smartphones, 
tablets, or computers. These notifications may include text alerts, 
images, or video clips captured by surveillance cameras. 
Video Surveillance: IP cameras integrated into the system enable real
time video monitoring of the premises. When triggered by sensor events, 
these cameras start recording and transmitting live video feed to the 
homeowners' devices. 
Remote Monitoring: The system allows home owners to remotely access 
and monitor their home's security status through a dedicated mobile app 
or a web interface. This feature provides peace of mind, especially when 
homeowners are away. 
Automated Responses: Depending on the severity of the detected 
intrusion, the system can initiate automated responses, such as activating 
security alarms, turning on lights, or even simulating the presence of 
occupants to deter potential intruders. 
 User Management: The system supports multiple user profiles, allowing 
different members of the household to have access to the system with 
varying levels of control and permissions.

# Steps followed for publishing value from esp8266 to mqtt broker 
 
Publishing a value from an ESP8266 to an MQTT broker involves 
several steps. MQTT (Message Queuing Telemetry Transport) is a 
lightweight messaging protocol used for IoT devices to communicate 
with each other. Here's a general outline of the steps you would follow 
to publish a value from an ESP8266 to an MQTT broker: 
1. Setup MQTT Broker: Choose an MQTT broker to use. Popular 
options include Mosquitto, HiveMQ, and Cloud-based solutions 
like CloudMQTT or Adafruit IO. Set up the broker according to 
the documentation provided by the chosen MQTT broker. 
2. Install Required Libraries: You'll need to install the necessary 
libraries to work with MQTT and the ESP8266. Two popular 
libraries are "PubSubClient" for MQTT communication and 
"ArduinoJson" for handling JSON data if needed. 
3. Connect to Wi-Fi: Initialize and connect the ESP8266 to your Wi
Fi network so that it can access the internet and communicate with 
the MQTT broker. 
4. Initialize MQTT Client: Initialize the MQTT client instance using 
the PubSubClient library. You'll need to provide the MQTT 
broker's IP address or domain, port, and callback functions for 
handling connection and message events. 
5. Connect to MQTT Broker: Use the client.connect() function to 
connect to the MQTT broker. Provide a unique client ID to identify 
your ESP8266. 
6. Publish Data: Once connected, you can use the client.publish() 
function to send data to a specific topic on the MQTT broker. 
Topics are like channels that help categorize and organize the data. 
7. Disconnect and Reconnect Handling: Implement code to handle 
disconnections and reconnect to the MQTT broker in case of 
network issues. You can use the client.loop() function to maintain 
the connection. 
Testing and Monitoring: Upload the code to your ESP8266 and monitor 
the Serial Monitor for debug messages. You can also use MQTT client 
tools or web interfaces provided by the MQTT broker to subscribe to the 
topic and observe the published data. 
By following these steps and customizing the code to your specific use 
case, you can successfully publish values from an ESP8266 to an MQTT 
broker and establish effective communication between your device and 
the broker. 
