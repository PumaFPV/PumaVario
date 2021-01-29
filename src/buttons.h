


void pin_mode_def()
{
  pinMode(button_pin, INPUT);
}



void process_buttons()
{

  button_state = digitalRead(button_pin);

}
