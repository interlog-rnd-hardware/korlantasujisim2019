#include <IRremote.h>

IRsend irsend;

void setup() {
}

void loop() {
    irsend.sendSony(0x1E2DD, 20);
    delay(100);
    irsend.sendSony(0x1E2DD, 20);
    delay(100);
    irsend.sendSony(0x1E2DD, 20);
    //delay(300000);
}
