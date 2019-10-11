/*
 * Infrared Decoder/Encoder
 * Hardware: Arduino Nano & DIY IR Sniffer Module
 * Library: IRremote by Ken Shirriff
 * Sketch: #1 - For Decoder
 * T.K.Hareendran/2018
 */

#include <IRremote.h>

int IRRX_PIN1 = 5; // D12 connected to Pin 3 of J1 – See schematic for J1 pin out!
int IRRX_PIN2 = 6;

IRrecv irrecv1(IRRX_PIN1);
IRrecv irrecv2(IRRX_PIN2);
decode_results results1;
decode_results results2;

void setup()
{
    Serial.begin(9600);
    irrecv1.enableIRIn();
    irrecv2.enableIRIn();
    digitalWrite(IRRX_PIN1,HIGH); // Optional Internal Pull-up
    digitalWrite(IRRX_PIN2,HIGH);
}

void loop() 
{
   Ir_1();
   Ir_2();
}
