#include "model.h"
#include <LiquidCrystal.h>

// ----------- SENSOR PINS ------------
const int LIGHT_PIN = A0;
const int TEMP_PIN  = A1;
const int HUMID_PIN = A2;

// ----------- LCD (PARALLEL) --------
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
    Serial.begin(9600);

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
    int rawHumid = analogRead(HUMID_PIN);

    // --- Normalize to 0–1 ---
    float light    = 100.0 - (rawLight * 100.0 / 1023.0); // or just rawlihgt * 100/ 1023.0 (depending on sensor type)
    float temp     = rawTemp * (5.0 / 1023.0) * 100.0; // normalize: (voltage/ max sensor value) * 100
    float humidity = rawHumid * 100 / 1023.0f; // might need to further normalize depending on the sensor

    // --- ML prediction ---
    float probRain = predict(temp, humidity, light);

    // --- Serial output ---
    Serial.print("Light=");
    Serial.print(light);
    Serial.print(" Temp=");
    Serial.print(temp);
    Serial.print(" Hum=");
    Serial.print(humidity);
    Serial.print(" Prob=");
    Serial.println(probRain);

    // --- LCD ---
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Rain prob:");

    lcd.setCursor(0, 1);
    lcd.print(probRain, 2);

    delay(1000);
}
