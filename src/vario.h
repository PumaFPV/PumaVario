
float tabPa1[10] = {0}; //20 to 11 last pressure measures
float tabPa2[10] = {0}; //10 last measures
float avPa1; //average value of tabPa1
float avPa2; //average value of tabPa2
float sumPa1;
float sumPa2;
float deltaPa;
float vario;
float expo_vario;
float vario_vitesse;

float algo_expo_mes_couilles(float alt)
{

}

float find_min(float tab[])
{
  float first = tab[0];
  for (int i = 1; i <= 9; i++) 
  {
    if (first > tab[i])
    {
      first = tab[i];
    };
  }
  return first;
}

float find_max(float tab[])
{
  float first = tab[0];
  for (int i = 1; i <= 9; i++) 
  {
    if (first < tab[i])
    {
      first = tab[i];
    };
  }
  return first;
}

void vario_init()
{
  for (int i = 0; i <= 9; i++ )
  {
    tabPa1[i] = ms5611.getAltitude(ms5611.readPressure());
    tabPa2[i] = ms5611.getAltitude(ms5611.readPressure());
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
    tabPa2[9] = ms5611.getAltitude(ms5611.readPressure());

    sumPa1 = 0;
    sumPa2 = 0;
    for (int i = 0; i <= 9; i++)
    {
      sumPa1 += tabPa1[i];
      sumPa2 += tabPa2[i];
    }
    avPa1 = (sumPa1 - find_max(tabPa1) - find_min(tabPa1))/8;
    avPa2 = (sumPa2 - find_max(tabPa2) - find_min(tabPa2))/8;
    deltaPa = avPa2 - avPa1;
    vario = varioKalmanFilter.updateEstimate(deltaPa);

    Serial.print("Vario: ");
    Serial.print(deltaPa * 10);
    Serial.print("    kalman: ");
    Serial.print(vario * 10);
    Serial.print("    Atli: ");
    Serial.println(ms5611.getAltitude(ms5611.readPressure(), 101325) - 532);
    delay(10);

/*
    if(vario > 0)
    {
      expo_vario = algo_expo_mes_couilles(vario);
    }
    else
    {
      expo_vario = -algo_expo_mes_couilles(-vario);
    }
*/
  tabPa2[9] = ms5611.getAltitude(ms5611.readPressure());
  sumPa1 = 0;
  sumPa2 = 0;
  for (int i = 0; i <= 9; i++)
  {
    sumPa1 += tabPa1[i];
    sumPa2 += tabPa2[i];
  }
  sumPa1 -= (find_min(tabPa1) + find_max(tabPa1));
  sumPa2 -= (find_min(tabPa2) + find_max(tabPa2));
  avPa1 = sumPa1/8;
  avPa2 = sumPa2/8;
  deltaPa = avPa2 - avPa1;
  vario = varioKalmanFilter.updateEstimate(deltaPa);
  Serial.print("    Vario: ");
  Serial.print(deltaPa * 10);
  Serial.print("    kalman: ");
  Serial.println(vario * 10);
  delay(10);

  if(vario > 0)
  {
    vario_vitesse = algo_expo_mes_couilles(vario);
  }
  else
  {
    vario_vitesse = -algo_expo_mes_couilles(-vario);
  }


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
