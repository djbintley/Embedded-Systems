#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define LEDMASK 0b0000000001001100
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut leds(PortC, LEDMASK);
PortOut onboardleds(PortB, 0b100000010000001);

int main()
{
    while (true) {
        leds = leds ^ LEDMASK;
        onboardleds = onboardleds ^ 0b100000010000001;
        wait_us(500000);
    }
}




