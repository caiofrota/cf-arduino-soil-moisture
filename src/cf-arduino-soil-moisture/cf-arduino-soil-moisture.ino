/**
 * CF Wi-Fi Soil Moisture Sensor.
 * 
 * IoT - Configurable soil moisture using ESP8266 (NodeMCU 1.0 ESP-12E), soil moisture sensor and ThingsBoard as server.
 * 
 * @author  Caio Frota <contact@cftechsol.com>
 * @version 2.0.0
 * @since   Feb, 2021
 */

//#define USE_DISPLAY                                                                                 // Comment this line if you won't use display.

// Libraries.
#include <ArduinoJson.h>                                                                            // Arduino JSON.
#include <Logger.h>                                                                                 // Logger.
#include <SPI.h>                                                                                    // SPI.
#include <ThingsBoard.h>                                                                            // Things Board.
#include <WiFiManager.h>                                                                            // Wi-Fi Manager.
#include <Wire.h>                                                                                   // Wire.

// Libraries Display.
#ifdef USE_DISPLAY
    #include <Adafruit_GFX.h>                                                                       // Adafruit GFX.
    #include <Adafruit_SSD1306.h>                                                                   // Adafruit display.
#endif

// Application attributes.
const char* appSketch = "cf-arduino-soil-moisture";                                                 // Application sketch.
const char* appVersion = "2.0.0";                                                                   // Application version.

void setup() {
    // Start Serial Monitor.
    Serial.begin(9600);
    //Logger::setLogLevel(Logger::VERBOSE);

    // Start display, if declared.
    #ifdef USE_DISPLAY
        displayBegin();
    #endif
    
    wifiManagerBegin();
}

void loop() {
    soilmLoop();
    wifiManagerLoop();                                                                              // Wi-Fi Manager loop.
    tbLoop();                                                                              // ThingsBoard loop.
    
    #ifdef USE_DISPLAY
        displayLoop();                                                                              // Display loop.
    #endif
    
    delay(1000);
}
