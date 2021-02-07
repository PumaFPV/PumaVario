#ifndef variables_h  
#define variables_h  //gratuit et nécessaire pour les includes


//--------------------------------------------------Include libraries--------------------------------------------------

// include library, include base class, make path known
#include <GxEPD.h> //screen
#include <GxGDEH0213B73/GxGDEH0213B73.h>  // 2.13" b/w newer panel (OUR screen)
#include <SD.h> //SD card
#include <SPI.h> //comms SD
#include <TinyGPS++.h>// GPS
#include <Wire.h>//comms I2C (baro,MPU(acc,gyro,mag))
#include <MS5611.h>//baro
#include <MPU9250.h>//MPU
#include <SimpleKalmanFilter.h>//data filter (smoooooth criminal)
#include <Tone32.h>//Buzzer


// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>//comms screen



//--------------------------------------------------Define--------------------------------------------------

//Pins
#define I2C_SDA 21
#define I2C_SCL 22

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

MS5611 MS5611(0x77);   // 0x76 = CSB to VCC; 0x77 = CSB to GND

/*
SimpleKalmanFilter pressureKalmanFilter(3, 3, 0.8);
SimpleKalmanFilter varioKalmanFilter(0.9, 0.9, 1);
*/

//--------------------------------------------------Variables--------------------------------------------------

int page = 0;

//----------Display
void page0();
void page1();
void page2();
void page3();
void page4();
void page5();

//----------BMP

//----------SD
bool sd_ok = false;

//----------Button
bool button_state;

//----------Vario
float vario_min_threshold = -1.5;
float vario_max_threshold = 1;

//----------KML




#endif
