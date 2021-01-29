void mpu_setup()
{
  mpu.setup();

  delay(5000);

  // calibrate anytime you want to
  //mpu.calibrateAccelGyro();
  //mpu.calibrateMag();

  //mpu.printCalibration();
};



void mpu_loop()
{
    static uint32_t prev_ms = millis();
    if ((millis() - prev_ms) > 16)
    {
        mpu.update();
        //mpu.print();

        /*
        Serial.print("  ");
        Serial.print(mpu.getRoll());
        Serial.print("  ");
        Serial.print(mpu.getPitch());
        Serial.print("  ");
        Serial.println(mpu.getYaw());
        //*/

        prev_ms = millis();
    }
};
