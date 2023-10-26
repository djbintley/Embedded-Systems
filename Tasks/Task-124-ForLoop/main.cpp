#include "mbed.h"
#include "myutils.hpp"

// DigitalOut redLED(PC_2,0);
// DigitalOut yellowLED(PC_3,0);
// DigitalOut greenLED(PC_6,0);
BusOut leds(PC_2, PC_3, PC_6);

// main() runs in its own thread in the OS
int main()
{
    int pattern, patternCheck;
    int count, countCheck;
    int delay, delayCheck;
    do{
        flushInputBuffer();
        printf("\nEnter Pattern (0-7): \n");
        patternCheck = scanf("%d", &pattern);

        flushInputBuffer();
        printf("\nEnter Count (5-20): \n");
        countCheck = scanf("%d", &count);

        flushInputBuffer();
        printf("\nEnter Delay (50-2000): \n");
        delayCheck = scanf("%d", &delay);
    } while( (pattern < 0) || (pattern > 7) || (count < 5) || (count > 20) || (delay < 50) || (delay > 2000) || (delayCheck < 1) || (countCheck < 1) || (delayCheck < 1) );

    while (true) {

        //For-Loop
        for (int n=7; n>=0; n = n-2) {
            printf("n=%d\n", n);
            leds = n;
            wait_us(250000);
        }

        //2s pause
        wait_us(2000000);
    }
}

