#include "uop_msb.h"
using namespace uop_msb;

BusIn bus(PG_0, PG_1);
DigitalIn ButtonC(PG_2, PullDown); //Button C
DigitalIn ButtonD(PG_3, PullDown); //Button D

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    int count = 1;

    //Turn ON the 7-segment display
    disp.enable(true);

    //Update display
    disp = count;

    while (true) {
        
        //Test Button A
        if (bus == 1) {
            redLED = !redLED;    //Toggle RED led
            count = count + 1;            //Increment count
            disp = count;       //Update display
        }
            //Test Button B
        else if (bus == 2) {
            redLED = !redLED;    //Toggle RED led
            count = count - 1;            //Increment count
            disp = count;       //Update display
        }
        else if(bus == 3){
            redLED = !redLED;
            count = 0;
            disp = count;
        }
        else{
            greenLED= !greenLED;
        }

        if (count == 99){
            count = 0;
            disp = count;
        }
        else if (count < 0 ){
            count = 99;
            disp = count;
        }
        // Slow it down a bit (and debounce the switches)
        wait_us(100000);  
    }
}


