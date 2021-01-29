void gps_display_info()
{

  //Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    //Serial.print(gps.location.lat(), 6);
    //Serial.print(F(","));
    //Serial.print(gps.location.lng(), 6);
  }
  else
  {
    //Serial.print(F("INVALID"));
  }

  //Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  { 
    //Serial.print(gps.date.day());
    //Serial.print(F("/"));
    //Serial.print(gps.date.month());
    //Serial.print(F("/"));
    //Serial.print(gps.date.year());
  }
  else
  {
    //Serial.print(F("INVALID"));
  }

  //Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    //Serial.print(gps.time.hour());
    //Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    //Serial.print(gps.time.minute());
    //Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    //Serial.print(gps.time.second());
    //Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    //Serial.print(gps.time.centisecond());
  }
  else
  {
    //Serial.print(F("INVALID"));
  }

  //Serial.println();
}



void gps_setup()
{
    Serial2.begin(4800, SERIAL_8N1, 15, 14);

    Serial.println(TinyGPSPlus::libraryVersion());
    while (Serial2.available() > 0)
        if (gps.encode(Serial2.read()))
            gps_display_info();

}



void gps_kml_path()
{
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
    Serial.print(F(","));
    Serial.println(gps.altitude.meters(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }
  
}
