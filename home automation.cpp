#include <ESP8266WiFi.h>   // Include Wi-Fi library for ESP8266
#include <BlynkSimpleEsp8266.h>   // Include Blynk library
#include <DHT.h>   // Include DHT sensor library (optional, if using for temperature/humidity sensing)

// Replace with your network credentials
const char *ssid = "Your_SSID";
const char *password = "Your_PASSWORD";

// Blynk authentication token
char auth[] = "Your_Blynk_Auth_Token";

// Pin assignments for the relays
const int relay1Pin = D1;  // Relay to control Light 1
const int relay2Pin = D2;  // Relay to control Light 2

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to Wi-Fi");

  // Connect to Blynk server
  Blynk.begin(auth, ssid, password);

  // Initialize relay pins as OUTPUT
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);

  // Ensure the relays are initially turned off
  digitalWrite(relay1Pin, LOW);
  digitalWrite(relay2Pin, LOW);
}

void loop() {
  Blynk.run();  // Initiates Blynk communication

  // Voice commands or manual control can be handled here
  // For example, Blynk buttons controlling relays
}

// Virtual pins to control the relay from Blynk app
BLYNK_WRITE(V1) {  // Control Light 1
  int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(relay1Pin, HIGH);  // Turn on Light 1
  } else {
    digitalWrite(relay1Pin, LOW);  // Turn off Light 1
  }
}

BLYNK_WRITE(V2) {  // Control Light 2
  int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(relay2Pin, HIGH);  // Turn on Light 2
  } else {
    digitalWrite(relay2Pin, LOW);  // Turn off Light 2
  }
}
