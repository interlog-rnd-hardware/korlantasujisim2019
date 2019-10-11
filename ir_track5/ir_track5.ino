#include <IRremote.h>

IRsend irsend;

void setup() {
}

void loop() {
    irsend.sendSony(0xB9921, 20);
    delay(100);
    irsend.sendSony(0xB9921, 20);
    delay(100);
    irsend.sendSony(0xB9921, 20);
    //delay(300000);
}
