#include "model.h"
// #include <LiquidCrystal.h>

//-------- HUMIDITY + TEMP sensor ---------
#include <DHT.h>

#define DHTPIN 7 //digital pin the sensor is connected to 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ----------- SENSOR PINS ------------
const int LIGHT_PIN = A0;


// ----------- LCD (PARALLEL) --------
// Wiring:
//
// RS -> pin 7
// E  -> pin 8
// D4 -> pin 9
// D5 -> pin 10
// D6 -> pin 11
// D7 -> pin 12
// LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
    Serial.begin(9600);
    dht.begin();
    // lcd.begin(16, 2);
    // lcd.clear();
    // lcd.setCursor(0, 0);
    // lcd.print("WeatherPredict");
    // delay(1200);
}

void loop() {

    // --- Read sensors ---
    int rawLight = analogRead(LIGHT_PIN);
    float humidity = dht.readHumidity();       // %RH
    float temperature = dht.readTemperature(); // °C

    // --- Normalize to 0–1 ---
    float cloudCover    = 100.0 - (rawLight * 100.0 / 1023.0); // or just rawlihgt * 100/ 1023.0 (depending on sensor type)
    // float tempFahrenheit     = rawTemp * (5.0 / 1023.0) * 100.0; // normalize: (voltage/ max sensor value) * 100
    // float temp = (tempFahrenheit - 32) /1.8;

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
    } 

    // --- ML prediction ---
    float probRain = predict(temperature, humidity, cloudCover);

    // --- Serial output ---
    Serial.print("Clouds=");
    Serial.print(cloudCover);
    Serial.print(" Temp=");
    Serial.print(temperature);
    Serial.print(" Hum=");
    Serial.print(humidity);
    Serial.print(" Prob=");
    Serial.println(probRain);

    // --- LCD ---
    // lcd.clear();
    // lcd.setCursor(0, 0);
    // lcd.print("Rain prob:");

    // lcd.setCursor(0, 1);
    // lcd.print(probRain, 2);

    delay(1000);
}
