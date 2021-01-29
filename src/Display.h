void display_setup()
{
    display.init(); // enable diagnostic output on Serial

    display.setRotation(3);
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(0, 0);

   

    display.fillScreen(GxEPD_WHITE);
    display.drawBitmap(puma, 10, SCREEN_WIDTH / 2 - 32,  64, 64, GxEPD_BLACK);

    display.setFont(&FreeMonoBold24pt7b);
    display.setCursor(90, 35);
    display.println("Puma");
    display.setCursor(90, 70);
    display.print("Vario");
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(90, 93);
    display.print("v1.0");

    display.setCursor(SCREEN_LENGTH - 160, SCREEN_WIDTH - 1);
    display.setFont(&FreeMonoBold9pt7b);
    if (sd_ok)
    {
        uint32_t cardSize = SD.cardSize() / (1024 * 1024);
        display.println("SDCard:" + String(cardSize) + "MB");
    } 
    else 
    {
        display.println("SDCard  None");
    }
    display.update();

}



void display_loop()
{
    if (page == 0){ //--------------------------------------------------Page-0--------------------------------------------------
        page0();
    }

    if (page == 1){ //--------------------------------------------------Page-1--------------------------------------------------
        page1();
    }

    if (page == 2){ //--------------------------------------------------Page-2--------------------------------------------------
        page2();
    }


    if (page == 3){ //--------------------------------------------------Page-3--------------------------------------------------
        page3();
    }

    if (page == 4){ //--------------------------------------------------Page-4-------------------------------------------------- 
        page4();
    }

    if (page == 5){ //--------------------------------------------------Page-5--------------------------------------------------
        page5();
    }
    
}



void page0()
{
    display_setup();
}



void page1()
{
    display.fillRect(5, 0, 250, 80, GxEPD_WHITE);

    char result = bmp.startMeasurment();
 
    if(result!=0)
    {
        delay(result);
        result = bmp.getTemperatureAndPressure(T,P);
    
        if (result!=0)
        {
            A = bmp.altitude(P, P0);
        }
    }

    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(5,14);
    display.print("Baro alti = \t");
    display.print(A, 2); 
    display.println(" m");

    display.setCursor(5, 28);
    //display.print("GPS alti = \t"); display.print(gps.altitude.meters()); display.print(" m");
    display.print("GPS = \t"); display.print(gps.satellites.value()); display.print(" sats");

    display.setCursor(5, 42);
    display.print(gps.location.lat());
    display.setCursor(125, 42);
    display.print(gps.location.lng());

    display.updateWindow(5, 0, 250, 80, true);
}



void page2()
{
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(10,10);
    display.print("page 2");
}



void page3()
{
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(10,10);
    display.print("page 3");
}



void page4()
{
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(10,10);
    display.print("page 4");
}



void page5()
{
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(10,10);
    display.print("page 5");
}
