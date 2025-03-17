#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define PIEZO_PIN A0         // Piezo sensor connected to A0
#define BUZZER_PIN 8         // Buzzer connected to digital pin 8
#define THRESHOLD 800

        // Threshold value for triggering the buzzer

// Initialize OLED display (I2C address 0x3C)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  
  pinMode(PIEZO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  
  display.display();
  delay(3000);
  display.clearDisplay();
}

void loop() {
  int sensorValue = analogRead(PIEZO_PIN);  // Read piezo sensor value
  
  // Display value on OLED
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Vibration Value:");
  display.println(sensorValue);
  display.setTextSize(1);
  display.setCursor(0, 40);
  float voltage = sensorValue * (5.0 / 1023.0);
  display.print("Voltage is: ");
  display.print(voltage);
  display.println(" V");
  display.display();

  Serial.println(sensorValue);  // Print value to Serial Monitor

  // Trigger buzzer if value exceeds threshold
  if (sensorValue > THRESHOLD) {
    tone(BUZZER_PIN, 1000);     // Play a 1000 Hz tone
    delay(100);
    noTone(BUZZER_PIN);
  } else {
    noTone(BUZZER_PIN);
  }

  delay(100);  // Small delay to stabilize readings
}