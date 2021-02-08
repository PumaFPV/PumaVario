
float tabPa1[10] = {0}; //20 to 11 last pressure measures
float tabPa2[10] = {0}; //10 last measures
float avPa1; //average value of tabPa1
float avPa2; //average value of tabPa2
float sumPa1;
float sumPa2;
float deltaPa;

void vario_init()
{
  for (int i = 0; i <= 9; i++ )
  {
    tabPa1[i] = MS5611.getPressure();
    tabPa2[i] = MS5611.getPressure();
  }
}

void vario_loop()
{ 
  for (int i = 0; i <=8; i++)
    {
      tabPa1[i] = tabPa1[i+1];
    }
    tabPa1[9] = tabPa2[0];
  for (int i = 0; i <=8; i++)
    {
      tabPa2[i] = tabPa2[i+1];
    }
    tabPa1[9] = MS5611.getPressure();
    sumPa1 = 0;
    sumPa2 = 0;
    for (int i = 0; i <= 9; i++)
    {
      sumPa1 += tabPa1[i];
      sumPa2 += tabPa2[i];
    }
    avPa1 = sumPa1/10;
    avPa2 = sumPa2/10;
    deltaPa = avPa2 - avPa1;
  /*
  if(vario_kalman < vario_min_threshold)  // sinking
  {
    int freq = map(vario_kalman, -5, 0, 100, 500);
    tone(buzzer_pin, freq, 500, buzzer_channel);   //tone(BUZZER_PIN, freq, time, 0);
    noTone(buzzer_pin, buzzer_channel);
  }
  if(vario_kalman > vario_max_threshold)  // climbing
  {
    int freq = map(vario_kalman, 0, 5, 1000, 8000);
    tone(buzzer_pin, freq, 500, buzzer_channel);   //tone(BUZZER_PIN, freq, time, 0);
    noTone(buzzer_pin, buzzer_channel);    
  }
  */
}
