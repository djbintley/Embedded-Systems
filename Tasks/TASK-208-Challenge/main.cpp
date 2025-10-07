#include "uop_msb.h"
using namespace uop_msb;

// Inputs
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);
DigitalOut ledYel(TRAF_YEL1_PIN);
DigitalOut ledGrn(TRAF_GRN1_PIN);

// Timers (modified version from Timer)
TimerCompat tmr_flash;
TimerCompat tmr_sw2;
TimerCompat tmr_sw3;

char pressed1;
char pressed2;

int main()
{
    //Start flashing timer
    tmr_flash.start();

    while (true) {
        if (pressed1 == 0){
            if (SW2 == 1){
                tmr_sw2.reset();
                wait_us(20000);
                if(SW2 == 1){
                    pressed1 = 1;
                }
            }
        }else{
            if (SW2 == 0){
                tmr_sw2.reset();
                wait_us(20000);
                if (SW2 == 0){
                    ledRed = !ledRed;
                    pressed1 = 0;
                }
            }
        }

        if (pressed2 == 0){
            if (SW3 == 1){
                tmr_sw3.reset();
                wait_us(20000);
                if(SW3 == 1){
                    pressed2 = 1;
                }
            }
        }else{
            if (SW3 == 0){
                tmr_sw3.reset();
                wait_us(20000);
                if (SW3 == 0){
                    ledGrn = !ledGrn;
                    pressed2 = 0;
                }
            }
        }         

        //Toggle Yellow LED        
        if (tmr_flash.read_ms() > 500){
            tmr_flash.reset();
            ledYel = !ledYel;
        }
    }
}





