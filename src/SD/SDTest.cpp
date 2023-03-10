#include <Arduino.h>
#include <SPI.h>
#include <SdFat.h>

SdFat SD;

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("Initializing SD card...");

  if (!SD.begin(5, SD_SCK_MHZ(50))) {
    Serial.println("SD card initialization failed!");
    return;
  }

  Serial.println("SD card initialization done.");
  
  // Open file for writing
  FsFile file = SD.open("/test.txt", FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file for writing!");
    return;
  }

  // Write some text to file
  file.println("Hello, world!");
  file.println("This is a test file.");

  // Close the file
  file.close();

  Serial.println("File written successfully!");
}

void loop() {
  // Nothing to do here
}