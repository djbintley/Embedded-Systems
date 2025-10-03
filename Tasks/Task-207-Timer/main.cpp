#include "uop_msb.h"
using namespace uop_msb;

// Hardware Definitions
#define TRAF_RED1_PIN PC_2

// Inputs
DigitalIn SW_BLUE(USER_BUTTON);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);

// Timer(modified version from Timer)
TimerCompat tmr1;
char pressed = 0;

int main()
{
    //Time how long it takes to perform a printf
    tmr1.start();
    printf("Hello World How Are You\n");
    tmr1.stop();

    //Print out how long it took
    unsigned long long dur = tmr1.read_ms();
    printf("The time taken was %llu milliseconds\n", dur);    

    //Now to use a timer to implement a delay
    tmr1.start();
    while (true) {
        //Wait for switch press
        if (pressed == 0){
            if (SW_BLUE == 1){
                tmr1.reset();
                wait_us(20000);
                if(SW_BLUE == 1){
                    pressed = 1;
                }
            }
        }else{
            if (SW_BLUE == 0){
                tmr1.reset();
                wait_us(20000);
                if (SW_BLUE == 0){
                    ledRed = !ledRed;
                    pressed = 0;
                }
            }
        }
    }
}



