#include "uop_msb.h"
#include <chrono>
#include <cstdint>
#include <iostream>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn pot(AN_POT_PIN);
Buzzer buzz;

//BUZZ BUZZ BUZZ
void coolBuzz(const char *noteStr)
{
    printf("%s\n",noteStr);
    for(int i = 0;i < strlen(noteStr); i++){
        switch (noteStr[i])
                { 
                    case 'A':
                        if (noteStr[i+1]=='#') {
                            buzz.playTone("A#");

                            i++;
                        }
                        else buzz.playTone("A");
                        break;
                    case 'B':
                        if (noteStr[i+1]=='#') {
                            buzz.playTone("B#");
                            i++;
                        }
                        else buzz.playTone("B");
                        break;
                    case 'C':
                        if (noteStr[i+1]=='#') {
                            buzz.playTone("C#");
                            i++;
                        }
                        else buzz.playTone("C");
                        break;
                    case 'D':
                        if (noteStr[i+1]=='#') {
                            buzz.playTone("D#");
                            i++;
                        }
                        else buzz.playTone("D");
                        break;
                    case 'E':
                        if (noteStr[i+1]=='#') {
                            buzz.playTone("E#");
                            i++;
                        }
                        else buzz.playTone("E");
                        break;
                    case 'F':
                        if (noteStr[i+1]=='#') {
                            buzz.playTone("F#");
                            i++;
                        }
                        else buzz.playTone("F");
                        break;
                    case 'G':
                        if (noteStr[i+1]=='#') {
                            buzz.playTone("G#");
                            i++;
                        }
                        else buzz.playTone("G");
                        break;
                    default:
                        buzz.rest();                  
                        break;
                }
    wait_us(200000);
    }
    buzz.rest();
}


//BUZZ BUZZ BUZZ

int main()
{

coolBuzz("AAAAAAFCAAFCAAAAEEEEEEFCAAFCAAAA");
while(1){}

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
                buzz.playTone("G", Buzzer::HIGHER_OCTAVE);
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

