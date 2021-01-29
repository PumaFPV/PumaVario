//double A;
float vario_kalman;

void baro_setup()
{
  if(!bmp.begin())
  {
    Serial.println("BMP init failed!");
    while(1);
  }
  else Serial.println("BMP init success!");
  
  bmp.setOversampling(4);
};



void baro_loop()
{
  //double T,P;
  char result = bmp.startMeasurment();
 
  if(result!=0)
  {
    delay(result);
    result = bmp.getTemperatureAndPressure(T,P);
    
      if (result!=0)
      {
        A = bmp.altitude(P, P0);
        Serial.print(A);
        float estimated_altitude = pressureKalmanFilter.updateEstimate(A);
        //Serial.print("T = \t");Serial.print(T,2); Serial.print(" degC\t");
        //Serial.print("P = \t");Serial.print(P,2); Serial.print(" mBar\t");
        //Serial.print("A = \t");
        //Serial.print(A,2);
        Serial.print(" ");
        Serial.println(estimated_altitude); 
        //Serial.println(" m");

        unsigned long baro_current_millis = millis();
        
        if(baro_current_millis - baro_previous_millis >= baro_interval)
        {
            baro_previous_millis = baro_current_millis;
            bmp.startMeasurment();
            bmp.getTemperatureAndPressure(T,P);
            float new_altitude = pressureKalmanFilter.updateEstimate(bmp.altitude(P,P0));
            float vario = new_altitude - estimated_altitude;
            vario = vario * 50;
            vario_kalman = varioKalmanFilter.updateEstimate(vario);// * 40;
            /*
            Serial.print("alti: ");
            Serial.print(bmp.altitude(P,P0));           
            Serial.print("  vario: ");
            Serial.println(new_altitude);
            */
        }
        
      }
      else 
      {
        Serial.println("Error.");
      }
  }
  else 
  {
    Serial.println("Error.");
  }

};
