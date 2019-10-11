/*
 *
 * IRremote: IRsendMulti - demonstrates sending IR codes with IRsend with three parallel IR diodes.
 * An IR LED must be connected to Arduino PWM pin 3, 9 and 10:
 *
 * Tested on Arduino UNO board:
 * IRsend  - pin 3
 * IRsend1 - pin 9
 * IRsend2 - pin 10
 *
 * Original version of IRsend 
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * Idea of three parallel IR diodes
 * by khair-eddine 2015 Apr
 * https://github.com/khair-eddine
 *
 * Working library code for three parallel IR by
 * Tomas Stasiukaitis 2016
 * http://stasiukaitis.lt
 *
 */

#include <IRremote.h>

IRsend  irsend0;
IRsend1 irsend1;
IRsend2 irsend2;

void setup()
{
  Serial.begin(9600);
}

void loop() {
    irsend0.sendSony(0x68B92, 20);
    delay(100);
    irsend1.sendSony(0x68B77, 20);
    delay(100);
    //irsend1.sendSony(0xB9921, 20);
    }
