#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "HoneyPot";     // replace with your WiFi network name
const char* password = "10marnovied2015"; // replace with your WiFi network password


// IPAddress ip(192, 168, 1, 177);      // replace with your desired IP address
// IPAddress gateway(192, 168, 1, 1);   // replace with your gateway IP address
// IPAddress subnet(255, 255, 255, 0); // replace with your subnet mask
// IPAddress dns(192, 168, 1, 1);

void setup() {
  Serial.begin(115200);

  // Connect to WiFi network
  Serial.println(WiFi.begin(ssid, password));

  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println("...");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(WiFi.status());
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Print the local IP address
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Nothing to do here
}


