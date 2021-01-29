#ifndef variables_h
#define variables_h



//--------------------------------------------------Include libraries--------------------------------------------------

// include library, include base class, make path known
#include <GxEPD.h>
#include <GxGDEH0213B73/GxGDEH0213B73.h>  // 2.13" b/w newer panel
#include <SD.h>
#include <SPI.h>
#include <TinyGPS++.h>
#include <Wire.h>
#include <BMP280.h>
#include <MPU9250.h>
#include <SimpleKalmanFilter.h>
#include <Tone32.h>


// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>



//--------------------------------------------------Define--------------------------------------------------

//Pins
#define SPI_MOSI 23
#define SPI_MISO -1
#define SPI_CLK 18

#define ELINK_SS 5
#define ELINK_BUSY 4
#define ELINK_RESET 16
#define ELINK_DC 17

#define SDCARD_SS 13
#define SDCARD_CLK 14
#define SDCARD_MOSI 15
#define SDCARD_MISO 2

#define button_pin 39

#define buzzer_pin 12
#define buzzer_channel 0

//Data
#define SCREEN_LENGTH 250
#define SCREEN_WIDTH 122


//--------------------------------------------------Initialize libraries--------------------------------------------------

GxIO_Class io(SPI, /*CS=5*/ ELINK_SS, /*DC=*/ ELINK_DC, /*RST=*/ ELINK_RESET);
GxEPD_Class display(io, /*RST=*/ ELINK_RESET, /*BUSY=*/ ELINK_BUSY);

SPIClass sdSPI(VSPI);

TinyGPSPlus gps;

MPU9250 mpu;

BMP280 bmp;

SimpleKalmanFilter pressureKalmanFilter(3, 3, 0.8);
SimpleKalmanFilter varioKalmanFilter(0.9, 0.9, 1);



//--------------------------------------------------Variables--------------------------------------------------

float P0 = 1013.25;

int page = 0;

//----------Display
void page0();
void page1();
void page2();
void page3();
void page4();
void page5();

//----------BMP
void baro_loop();
float get_baro_altitude();
double T, P, A;

unsigned long baro_previous_millis = 0;        // will store last time LED was updated

const long baro_interval = 500;           // interval at which to blink (milliseconds)


bool sd_ok = false;

bool button_state;

//----------Vario
float vario_min_threshold = -1.5;
float vario_max_threshold = 1;

//----------KML




#endif
