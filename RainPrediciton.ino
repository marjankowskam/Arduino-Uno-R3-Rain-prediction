#include "model.h"
#include <LiquidCrystal.h>

// ----------- SENSOR PINS ------------
const int LIGHT_PIN = A0;
const int TEMP_PIN  = A1;

// ----------- LCD (PARALLEL) --------
// Wiring:
//
// RS -> pin 7
// E  -> pin 8
// D4 -> pin 9
// D5 -> pin 10
// D6 -> pin 11
// D7 -> pin 12
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
    Serial.begin(9600);

    // Initialize LCD
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WeatherPredict");
    delay(1200);
}

void loop() {

    // --- Read sensors ---
    int rawLight = analogRead(LIGHT_PIN);
    int rawTemp  = analogRead(TEMP_PIN);

    // --- Normalize to 0–1 (adjust if needed based on training) ---
    float light = rawLight / 1023.0f;
    float temp  = rawTemp  / 1023.0f;

    // --- ML prediction ---
    float probRain = predict(light, temp);  
    // predict() already applies sigmoid

    // --- Serial output (for debugging) ---
    Serial.print("Light=");
    Serial.print(light);
    Serial.print(" Temp=");
    Serial.print(temp);
    Serial.print(" Prob=");
    Serial.println(probRain);

    // --- Display on LCD (simple) ---
    lcd.clear();
    lcd.setCursor(0, 0);
    // lcd.print("RainProb:");

    lcd.setCursor(0, 1);
    lcd.print(probRain, 2); // show 2 decimals (0.00–1.00)

    delay(1000);
}
