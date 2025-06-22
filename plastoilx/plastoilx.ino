#include <LiquidCrystal.h>

// Pin connections
const int lm35Pin = A0;      // LM35 temperature sensor
const int relayLedPin = 7;   // Heater simulated by LED

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(relayLedPin, OUTPUT);
  lcd.begin(16, 2);  // Initialize 16x2 LCD
  lcd.print("System Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read LM35 analog voltage
  int sensorValue = analogRead(lm35Pin);
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert to volts
  float temperatureC = voltage * 100.0;          // Convert to °C

  // Display temperature on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C   ");

  // Control heater (LED)
  if (temperatureC >= 60) {
    digitalWrite(relayLedPin, HIGH); // Heater ON
    lcd.setCursor(0, 1);
    lcd.print("Heater: ON ");
  } else {
    digitalWrite(relayLedPin, LOW);  // Heater OFF
    lcd.setCursor(0, 1);
    lcd.print("Heater: OFF");
  }

  delay(1000);
}
