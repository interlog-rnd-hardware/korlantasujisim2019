/**
 * Author:Ab Kurk
 * version: 1.0
 * date: 24/01/2018
 * Description: 
 * This sketch is part of the beginners guide to putting your Arduino to sleep
 * tutorial. It is to demonstrate how to put your arduino into deep sleep and
 * how to wake it up.
 * Link To Tutorial http://www.thearduinomakerman.info/blog/2018/1/24/guide-to-arduino-sleep-mode
 */

#include <avr/sleep.h>//this AVR library contains the methods that controls the sleep modes
#include <SoftwareSerial.h>

#define interruptPin 2 //Pin we are going to use to wake up the Arduino
#define ind 6
#define gnd 7
#define set 12
#define voltpin A0
#define prox 7

SoftwareSerial HC12(11, 10); // HC-12 TX Pin, HC-12 RX Pin

String sendong;
String track = "5";
String nmr = "01";
String jns = "2";
String sprox;

char csendong[13];

boolean tidurlagi;
  
int statecones;
int a;
int stateprox;

float b,voltage;

void setup() {
  Serial.begin(4800);//Start Serial Comunication
  HC12.begin(4800);
  pinMode(LED_BUILTIN,OUTPUT);//We use the led on pin 13 to indecate when Arduino is A sleep
  pinMode(prox, INPUT);
  pinMode(set, OUTPUT);
  pinMode(interruptPin,INPUT);//Set pin d2 to input using the buildin pullup resistor
  digitalWrite(LED_BUILTIN,HIGH);//turning LED on
  tidurlagi = false;
  pinMode(ind, INPUT);
  digitalWrite(gnd,LOW);
  digitalWrite(set,HIGH);
}

void loop() 
{
 delay(200);//wait 5 seconds before going to sleep
 Going_To_Sleep();
}

void Going_To_Sleep(){
    sleep_enable();//Enabling sleep mode
    attachInterrupt(0, bangun, CHANGE);//attaching a interrupt to pin d2
    attachInterrupt(1, bangun, CHANGE);//attaching a interrupt to pin d3
    Serial.println("Tidur!");
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);//Setting the sleep mode, in our case full sleep
    digitalWrite(LED_BUILTIN,LOW);//turning LED off;
    delay(200); //wait a second to allow the led to be turned off before going to sleep
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);//Setting the sleep mode, in our case full sleep
    sleep_cpu();//activating sleep mode
    delay(1000);
    kondisi();
  }
void bangun(){
  Serial.println("Dibangunin");//Print message to serial monitor
  delay(100);
  sleep_disable();//Disable sleep mode
  delay(200);
  detachInterrupt(0); //Removes the interrupt from pin 2;
  digitalWrite(LED_BUILTIN,HIGH);//turning LED off;
  delay(250);
  kirim();
  delay(100);
}

void kirim()
{
  statecones = digitalRead(ind);
  stateprox = digitalRead(prox);
  sprox = String(stateprox);
  Serial.println(sprox);
//  a = analogRead(voltpin);
//  b = (a / 1023) * 1.3;
  voltage = ((analogRead(voltpin) * 1.3) / 1023) + 2.9;
//  Serial.println(statecones);
  if (statecones == LOW && stateprox == HIGH)
  {
  sendong = "<" +track + "~" + nmr + "~" + "1" + "~" + jns +"~"+ sprox + "~" + voltage + ">";
  }
  if(statecones == HIGH && stateprox == LOW)
  {
  sendong = "<" + track + "~" + nmr + "~" + "0" + "~" + jns +"~"+ "1" + "~" + voltage + ">";
  }
    if(statecones == LOW && stateprox == LOW)
  {
  sendong = "<" + track + "~" + nmr + "~" + "1" + "~" + jns +"~"+ sprox + "~" + voltage + ">";
  }
    if(statecones == HIGH && stateprox == HIGH)
  {
  sendong = "<" + track + "~" + nmr + "~" + "0" + "~" + jns +"~"+ "1"+ "~" + voltage + ">";
  }
  delay(50);
  HC12.println(sendong);
}

//void kirimbentar()
//{
//  statecones = digitalRead(ind);
//  stateprox = digitalRead(prox);
//  sprox = String(stateprox);
//  Serial.println(sprox);
////  a = analogRead(voltpin);
////  b = (a / 1023) * 1.3;
//  voltage = ((analogRead(voltpin) * 1.3) / 1023) + 2.9;
//  if (statecones == LOW && stateprox == HIGH)
//  {
//  Serial.println(sprox);
//  sendong = "<" +track + "~" + nmr + "~" + "1" + "~" + jns +"~"+ sprox + "~" + voltage + ">";
//  }
//  if(statecones == HIGH && stateprox == LOW)
//  {
//    Serial.println(sprox);
//  sendong = "<" + track + "~" + nmr + "~" + "0" + "~" + jns +"~"+ sprox + "~" + voltage + ">";
//  }
//    if(statecones == LOW && stateprox == LOW)
//  {
//    Serial.println(sprox);
//  sendong = "<" + track + "~" + nmr + "~" + "1" + "~" + jns +"~"+ sprox + "~" + voltage + ">";
//  }
//    if(statecones == HIGH && stateprox == HIGH)
//  {
//    Serial.println(sprox);
//  sendong = "<" + track + "~" + nmr + "~" + "0" + "~" + jns +"~"+ sprox + "~" + voltage + ">";
//  }
//  
//   delay(50);
//  HC12.println(sendong);
//}
void kondisi()
{
  statecones = digitalRead(ind);
  stateprox  = digitalRead(prox); 
  while (statecones == LOW || stateprox == HIGH)
 {
   statecones = digitalRead(ind);
   digitalWrite(LED_BUILTIN,LOW);//turning LED off;
   sleep_enable();
   attachInterrupt(0, bangun, RISING);
   attachInterrupt(1, bangun, RISING);
   Serial.println("tidurlagi");
   set_sleep_mode(SLEEP_MODE_PWR_DOWN);//Setting the sleep mode, in our case full sleep
   sleep_cpu();
   Serial.println("Sudah stand by lagi");
  if (statecones == LOW || stateprox == HIGH)
  {
    break;
  }
 }
}
