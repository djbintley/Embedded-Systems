#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Fun output stuff
LCD_16X2_DISPLAY disp;
Buzzer buzz;
LatchedLED ledDisp(LatchedLED::STRIP);

//Analogue Inputs
AnalogIn pot(AN_POT_PIN);
AnalogIn ldr(AN_LDR_PIN);
AnalogIn mic(MIC_AN_PIN);
int fred;

DigitalOut redLED(PC_2,1);
DigitalOut yellowLED(PC_3,1);
DigitalOut greenLED(PC_6,1);



int main()
{
int count = 1;
    //Test LED Bar Display
    ledDisp.enable(true);

    ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(100000);
    }
    ledDisp = 0;

    ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(100000);
    }
    ledDisp = 0;
    
    ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(100000);
    }     
    ledDisp = 0;


    while (true) {
        //Read Analog to Digital Converter values (16 bit)
        unsigned short potVal   = pot.read_u16();
        unsigned short lightVal = ldr.read_u16();
        unsigned short micVal   = mic.read_u16(); 
        fred = abs(micVal - 0x8000);
        if (fred > 500){
            redLED = 1;
        }
        else{
            redLED = 0;
        }
        if(lightVal < 0x500){
        greenLED = 1;
        }
        else{
            greenLED = 0;
        }
        if(potVal > 0x8000){
            yellowLED = 1;
        }
        else{
            yellowLED = 0;
        }

        ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
        ledDisp = (pow(2,((potVal/8192)+1))-1);

        ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
        ledDisp = (pow(2,((lightVal/608)+1))-1);

        //ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
        //ledDisp = (pow(2,(((1/(lightVal/608))*8)+1))-1);

        ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
        ledDisp = (pow(2,(fred/1000))-1);
        
        //Write to terminal
        printf("--------------------------------\n");
        printf("Potentiometer: %X\n", potVal);
        printf("Light Dependant Resistor: %X\n", lightVal);
        printf("Microphone: %X\n", micVal);   
        printf("Signed Microphone: %d\n", fred);   
  

        //ledDisp = count;
        if (count > 64){
            count = 1;
        }
        else{
            count = count * 2;
        }
        
        //Wait 0.25 seconds
        wait_us(250000);

    }
}

