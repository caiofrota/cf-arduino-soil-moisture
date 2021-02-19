/**
 * CF Wi-Fi Soil Moisture Sensor.
 * 
 * IoT - Configurable soil moisture using ESP8266 (NodeMCU 1.0 ESP-12E), soil moisture sensor and ThingsBoard as server.
 * 
 * @author  Caio Frota <contact@cftechsol.com>
 * @version 1.0
 * @since   Feb, 2021
 */

// Libraries.
#include "WiFiManager.h"                                                                            // Wi-Fi Manager.
#include "ArduinoJson.h"                                                                            // Arduino Json.
#include "ThingsBoard.h"                                                                            // Things Board.
#include "Logger.h"                                                                                 // Logger.

// Application attributes.
const char* appSketch = "cf-arduino-soil-moisture";                                                 // Application sketch.
const char* appVersion = "1.0.0";                                                                   // Application version.

#define PIN_SOILM           A0                                                                      // Soil Moisture Sensor.

WiFiClient wifiClient;                                                                              // Wi-Fi.
WiFiServer wifiServer(80);                                                                          // Wi-Fi.
WiFiManager wifiManager;                                                                            // Wi-Fi Manager.
ThingsBoard thingsBoard(wifiClient);                                                                // ThingsBoard.

// Custom Parameters.
WiFiManagerParameter wifiManagerCustomParameters[] = {                                              // Custom paramaters array.
    { "devicename", "Device Name", "", 50 },
    { "serverurl", "Server URL", "", 50 },
    { "token", "Token", "", 50 },
    { "soilm_airValue", "Air Value", "1023", 5 },
    { "soilm_waterValue", "Water Value", "0", 5 }
};
int wifiManagerCustomParametersSize = 5;                                                            // Custom parameters array size.

#define P_DEVICE_NAME                  0                                                            // Custom parameter index.
#define P_SERVER_URL                   1                                                            // Custom parameter index.
#define P_TOKEN                        2                                                            // Custom parameter index.
#define P_SOILM_AIR_VALUE              3                                                            // Custom parameter index.
#define P_SOILM_WATER_VALUE            4                                                            // Custom parameter index.

void setup() {
    // Start Serial Monitor.
    Serial.begin(9600);
    //Logger::setLogLevel(Logger::VERBOSE);
    
    // Start WiFiManager.
    wifiManagerBegin();
}

void loop() {
    wifiManagerLoop();                                                                              // Wi-Fi Manager loop.
    thingsBoardLoop();                                                                              // ThingsBoard loop.
    
    delay(1000);
}
