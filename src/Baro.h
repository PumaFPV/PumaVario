void baro_setup()
{
  if(MS5611.begin())
  {
    Serial.println("Baro init succeded");
  }
  else
  {
    Serial.println("Baro init failed");
  }
};



void baro_loop()
{

  int result = MS5611.read();
  if (result != MS5611_READ_OK)
  {
    Serial.print("Error in read: ");
    Serial.println(result);
  }
  else
  {
    Serial.print("\tP:\t");
    Serial.println(MS5611.getPressure(), 2);
  }

  delay(100);

};
