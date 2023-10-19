#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,0);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

//Object for controlling the LCD
LCD_16X2_DISPLAY lcd;

int main()
{
    while (true)
    {
        // lcd.puts("David's the Best     :)");
        red = 1;
        green = 0;
        amber = 0;
        lcd.puts("On Your Marks");
        wait_us(10000000);

        amber = 1;
        lcd.cls();
        lcd.puts("Get Set");
        wait_us(2000000);

        red = 0;
        amber = 0;
        green = 1;
        lcd.cls();
        lcd.puts("GOOOO!!!");    
        wait_us(10000000);

        green = 0;
        lcd.cls();
        for (int i = 0; i < 5; i++) {
            amber = 1;
            wait_us(500000);
            amber = 0;
            wait_us(500000);
        }
        
    }
    /*
    lcd.cls();
    lcd.puts("TASK-104");

    while (true)
    {
        red = !red;
        amber = !amber;
        green = !green;
        wait_us(WAIT_TIME_MS * 1000);
    }
    */
}
