


void vario_loop()
{
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
}
