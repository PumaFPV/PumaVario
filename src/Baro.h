double referencePressure;

void checkSettings()
{
  Serial.print("Oversampling: ");
  Serial.println(ms5611.getOversampling());
}

void baro_setup()
{
  // Initialize MS5611 sensor
  Serial.println("Initialize MS5611 Sensor");

  while(!ms5611.begin())
  {
    Serial.println("Could not find a valid MS5611 sensor, check wiring!");
    delay(500);
  }

  // Get reference pressure for relative altitude
  referencePressure = ms5611.readPressure();

  // Check settings
  checkSettings();
};

void baro_loop()
{

  // Read raw values
  uint32_t rawTemp = ms5611.readRawTemperature();
  uint32_t rawPressure = ms5611.readRawPressure();

  // Read true temperature & Pressure
  double realTemperature = ms5611.readTemperature();
  long realPressure = ms5611.readPressure();

  // Calculate altitude
  float absoluteAltitude = ms5611.getAltitude(realPressure);
  float relativeAltitude = ms5611.getAltitude(realPressure, referencePressure);


  Serial.print(relativeAltitude);    
  Serial.println(" m");

  delay(5);
};
