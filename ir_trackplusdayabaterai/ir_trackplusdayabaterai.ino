#include <IRremote.h>

#define load A0

IRsend irsend;

int baterai;
int persentase;
String spersen;
String whole;
char c[]= "04";
char d[9];

void setup() 
{
  Serial.begin(9600);
}

void loop() {
    //irsend.sendSony(0xB9921, 20);
    //delay(100);
    //irsend.sendSony(0xB9921, 20);
    //delay(100);
    //irsend.sendSony(0xB9921, 20);
    delay(100);
    hitungbatre();
    delay(100);
}

void hitungbatre()
{
  baterai = analogRead(load);
  //Serial.println(baterai);
  persentase = (baterai/1023.0)*100;
  //Serial.println(persentase);
  spersen = String(persentase,DEC);
  // Serial.println(spersen);
  whole += spersen;
  whole += c;
  whole.toCharArray(d,16); 
  //Serial.println(d);
  // irsend.sendSony(c, 20);
  //char BT_Input_Code[] = "2FD48B7";    //For example
  unsigned long value = strtoul(d, NULL, 10);
  Serial.println(value,DEC);
  irsend.sendSony(value, 32);
  whole="";

}
