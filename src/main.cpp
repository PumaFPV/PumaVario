#include "Variables.h"

#include "BitMap.h"
#include "buttons.h"
#include "SDcard.h"
#include "MPU.h"
#include "GPS.h"
#include "Baro.h"
#include "Display.h"
#include "vario.h"

void setup()
{

    Serial.begin(115200);
    Serial.println();
    Serial.println("setup");
    pin_mode_def();

    Wire.begin();

    //sd_setup();

    //gps_setup();

    display_setup();

    baro_setup();

    //mpu_setup();

    delay(500);
    display.fillScreen(GxEPD_WHITE);
    display.update();

}


void loop()
{

    baro_loop();
    //vario_loop();
    //display_loop();

    //mpu_loop();  //
    //process_buttons();


/*
    esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN, LOW);
    delay(1000);
    esp_deep_sleep_start();
*/
} 
