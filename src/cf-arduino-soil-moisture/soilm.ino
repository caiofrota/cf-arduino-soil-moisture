#define PIN_SOILM           A0                                                                      // Soil Moisture Sensor.

long soilMoistureValue = 0;                                                                         // Soil Moisture value (wet 0 - 1023 dry).
long soilMoisturePercentage = 0;                                                                    // Soil Moisture percentage (dry 0-100 wet).

/**
 * Collect Soil Moisture data.
 */
void soilmReadData() {
    int airValue = getWifiParamAirValue().toInt();
    int waterValue = getWifiParamWaterValue().toInt();
    
    soilMoistureValue = analogRead(PIN_SOILM);
    soilMoisturePercentage = map(soilMoistureValue, (airValue != waterValue) ? airValue : 1023, (airValue != waterValue) ? waterValue : 0, 0, 100);
    soilMoisturePercentage = (soilMoisturePercentage > 100) ? 100 : ((soilMoisturePercentage < 0) ? 0 : soilMoisturePercentage);
}

/**
 * Soil Moisture Loop.
 */
void soilmLoop() {
    soilmReadData();
}

/**
 * Get Soil Moisture value.
 */
long getSoilMoistureValue() {
    return soilMoistureValue;
}

/**
 * Get Soil Moisture percentage.
 */
long getSoilMoisturePercentage() {
    return soilMoisturePercentage;
}
