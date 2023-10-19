#include "mbed.h"

DigitalOut Red(PC_2,1);
DigitalOut Amber(PC_3,1);
DigitalOut Green(PC_6,1);


// main() runs in its own thread in the OS
int main()
{
    wait_us(1000000);
    Green = 0;
    while (true) {
        Red = 1;
        Amber = 0;
        wait_us(2000000);
        Amber = 1;
        wait_us(2000000);
        Red = 0;
        Amber = 0;
        Green = 1;
        wait_us(2000000);
        Green = 0;
        int counter = 0;
        while (counter < 4)
        {
            counter = counter + 1;
            Amber = 0;
            wait_us(500000);
            Amber = 1;
            wait_us(500000);
        } 
    }
}

