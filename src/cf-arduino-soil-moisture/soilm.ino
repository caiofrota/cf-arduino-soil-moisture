/**
 * Collect Soil Moisture data.
 * 
 * @return DynamicJsonDocument JSON data.
 */
DynamicJsonDocument readSoilMoistureData(int pin, String prefix, int airValue, int waterValue) {
    DynamicJsonDocument data(64);
    
    // Read Soil Moisture.
    long avgSoilMoisturePercentage = 0;
    long avgSoilMoistureValue = 0;
    for (int i = 0; i < 100; i++) {
        avgSoilMoistureValue += analogRead(pin);
        delay(1);
    }
    avgSoilMoistureValue = avgSoilMoistureValue / 100;
    avgSoilMoisturePercentage = map(avgSoilMoistureValue, (airValue != waterValue) ? airValue : 1023, (airValue != waterValue) ? waterValue : 0, 0, 100);
    avgSoilMoisturePercentage = (avgSoilMoisturePercentage > 100) ? 100 : ((avgSoilMoisturePercentage < 0) ? 0 : avgSoilMoisturePercentage);
    
    data[prefix + "_value"] = avgSoilMoistureValue;
    data[prefix + "_percentage"] = avgSoilMoisturePercentage;
    
    // Return data.
    return data;
}
