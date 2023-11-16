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
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;


int main()
{
    unsigned short samples[100] = {0};
    float mean = 0;
    enum {OFF=0, ON} state = OFF;
    int count = 0;
    int count2 = 1;
    int total = 0;
    
    /*
    for (unsigned int m=0; m<100; m++) {
        printf("%X \n", samples[m]);
    }
    */

    while (true) {

        unsigned short ldrVal   = ldr.read_u16();
        samples[count] = ldrVal;
        total = total + samples[count];
        total = total - samples[count2];
        mean = total/100.0;

        /*
        for (unsigned int m=0; m<100; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            samples[m] = ldrVal;
            wait_us(10000);          // 10ms
        }

        // TASK a. Calculate the average value in samples
        for (unsigned int m=0; m<100; m++) {
            mean = mean + samples[m];
        }
        mean = mean/sizeof(samples);
        */

        // TASK b. Display to 1dp

        printf("mean = %5.1f\n", mean);
        
        // TASK c. Switch green LED on when dark;

        switch (state) {
            case OFF:
                if (mean > 6000) {
                    state = ON;
                    greenLED = 1;
                    buzz.playTone("G#", Buzzer::HIGHER_OCTAVE);
                    
                }
                break;

            case ON:
                if (mean < 5000) {
                    state = OFF;
                    greenLED = 0;
                    //buzz.rest();
                }
                break;
        }

        count += 1;
        if (count == 100){
            count = 0;
        }

        count2 += 1;
        if (count2 == 100){
            count2 = 0;
        wait_us(7000);
        }


        
    }  
}