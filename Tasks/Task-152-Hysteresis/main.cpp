#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn pot(AN_POT_PIN);
Buzzer buzz;

int main()
{
int state = 0;
unsigned short potVal   = pot.read_u16();
    if (potVal > 0x8000){
        state = 1;
    }
    while (true) {
        //Read Analog to Digital Converter values (16 bit)
        unsigned short potVal   = pot.read_u16();
        printf("Potentiometer: %X\n", potVal);
        
        if (state == 0) {
            if (potVal > 0x9000){
                state = 1;
                redLED = 1;
                buzz.playTone("C");
            }
        } else {
            if(potVal < 0x7000){
                state = 0;
                redLED = 0;
                buzz.rest();
            }

        }

        //Wait 0.25 seconds
        wait_us(500000);

    }  
}

