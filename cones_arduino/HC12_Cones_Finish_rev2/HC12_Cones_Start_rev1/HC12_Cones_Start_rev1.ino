/**
 * Author:Ab Kurk
 * version: 1.0
 * date: 4/02/2018
 * Description: 
 * This sketch is part of the guide to putting your Arduino to sleep
 * tutorial. We use the:
 * Adafruit DS3231 RTC
 * Adafruit 5V ready Micro SD break out board
 * Arduino Pro Mini
 * DHT11 or DHT22 humidety/Temperature sensor
 * In this example we use the RTC to wake up the Arduino to log the temp and humidity on to an SD card.
 * After the data has been logged the Arduino goes back to sleep and gets woken up 5 minutes later to 
 * start all over again
 * Link To Tutorial http://www.thearduinomakerman.info/blog/2018/1/24/guide-to-arduino-sleep-mode
 * Link To Project   http://www.thearduinomakerman.info/blog/2018/2/5/wakeup-rtc-datalogger
 */

#include <avr/sleep.h>//this AVR library contains the methods that controls the sleep modes
#define interruptPin 2 //Pin we are going to use to wake up the Arduino
#include <DS3232RTC.h>  //RTC Library https://github.com/JChristensen/DS3232RTC
#include <SoftwareSerial.h>

#define interruptPin 2 //Pin we are going to use to wake up the Arduino
#define mgnt 6
#define prox 7
#define ind 8
#define gndprox 12
#define voltpin A0
#define RECV_PIN 5
#define smtr 4

const int time_interval=1;// Sets the wakeup intervall in minutes
int statecones;
int a;
int stateprox;
int motorid;
int adamtr=0;
int pjg;

float b,voltage;

char csendong[16];
char cmotor[3];

String sendong;
String track = "5";
String nmr = "00";
String jns = "2";
String sprox;
String motor;
String s;
String smpn="";

SoftwareSerial HC12(10, 11);

void setup() {
  Serial.begin(4800);//Start Serial Comunication
  HC12.begin(4800);
  
  pinMode(LED_BUILTIN,OUTPUT);//We use the led
//  on pin 13 to indecate when Arduino is A sleep
  pinMode(interruptPin,INPUT_PULLUP);//Set pin d2 to input using the buildin pullup resistor
  pinMode(interruptPin,INPUT);//Set pin d2 to input using the buildin pullup resistor
  pinMode(prox, INPUT);
  pinMode(mgnt, INPUT);
  pinMode(ind,INPUT_PULLUP);
  pinMode(gndprox,OUTPUT);
  pinMode(smtr,OUTPUT);
  
  digitalWrite(LED_BUILTIN,HIGH);//turning LED on
  digitalWrite(gndprox,HIGH);
  
  // initialize the alarms to known values, clear the alarm flags, clear the alarm interrupt flags
//    RTC.setAlarm(ALM1_MATCH_DATE, 0, 0, 0, 1);
//    RTC.setAlarm(ALM2_MATCH_DATE, 0, 0, 0, 1);
//    RTC.alarm(ALARM_1);
//    RTC.alarm(ALARM_2);
//    RTC.alarmInterrupt(ALARM_1, false);
//    RTC.alarmInterrupt(ALARM_2, false);
//    RTC.squareWave(SQWAVE_NONE);
    /*
     * Uncomment the block block to set the time on your RTC. Remember to comment it again 
     * otherwise you will set the time at everytime you upload the sketch
     * /
     /* Begin block
     tmElements_t tm;
    tm.Hour = 00;               // set the RTC to an arbitrary time
    tm.Minute = 00;
    tm.Second = 00;
    tm.Day = 4;
    tm.Month = 2;
    tm.Year = 2018 - 1970;      // tmElements_t.Year is the offset from 1970
    RTC.write(tm);              // set the RTC from the tm structure
     Block end * */
    time_t t; //create a temporary time variable so we can set the time and read the time from the RTC
    t=RTC.get();//Gets the current time of the RTC
//    RTC.setAlarm(ALM1_MATCH_MINUTES , 0, minute(t)+time_interval, 0, 0);// Setting alarm 1 to go off 5 minutes from now
//    // clear the alarm flag
//    RTC.alarm(ALARM_1);
//    // configure the INT/SQW pin for "interrupt" operation (disable square wave output)
    RTC.squareWave(SQWAVE_NONE);
//    // enable interrupt output for Alarm 1
    RTC.alarmInterrupt(ALARM_1, true);
}

void loop() {
 delay(75);//wait 5 seconds before going to sleep. In real senairio keep this as small as posible
 time_t t; 
 t=RTC.get();
 if (hour(t) >= 8 && hour(t) < 17)
 {
  kondisi();
 }
 if (hour(t) >= 17)
 {
  //delay(1000);
  Going_To_Sleep();
  //kondisi();
 }
}

void Going_To_Sleep(){ 
  digitalWrite(LED_BUILTIN,LOW);
  Serial.println("tidur ah");
  delay(1000);
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  time_t t; 
  t=RTC.get();
  RTC.setAlarm(ALM1_MATCH_HOURS , 0, 00, 8, 0);
  // clear the alarm flag
  RTC.alarm(ALARM_1);
    //Enabling sleep mode
    attachInterrupt(0, wakeUp, LOW);//attaching a interrupt to pin d2
    //Setting the sleep mode, in our case full sleep
   //turning LED off
    //time_t t;// creates temp time variable
    Serial.println("Sleep  Time: "+String(hour(t))+":"+String(minute(t))+":"+String(second(t)));//prints time stamp on serial monitor
    delay(1000); //wait a second to allow the led to be turned off before going to sleep

    sleep_cpu();//activating sleep mode
    Serial.println("just woke up!");//next line of code executed after the interrupt 
    digitalWrite(LED_BUILTIN,HIGH);//turning LED on
    //temp_Humi();//function that reads the temp and the humidity
    t=RTC.get();
    Serial.println("WakeUp Time: "+String(hour(t))+":"+String(minute(t))+":"+String(second(t)));//Prints time stamp 
  }

void wakeUp(){
  Serial.println("Interrrupt Fired");//Print message to serial monitor
   sleep_disable();//Disable sleep mode
  detachInterrupt(0); //Removes the interrupt from pin 2;
 
}

 void kirim()
{
  statecones = digitalRead(mgnt);
  stateprox = digitalRead(prox);
  sprox = String(stateprox);
  Serial.println(sprox);
//  a = analogRead(voltpin);
//  b = (a / 1023) * 1.3;
  voltage = ((analogRead(voltpin) * 1.3) / 1023) + 2.9;
//  Serial.println(statecones);
  if (statecones == LOW && stateprox == HIGH)
  {
//    sendong = "ST1~1~0~" + String(motor) + "~" + String(voltage);
//     sendong = "S1~11"+String(motor);                                             
    sendong = "S3~10~"+String(motor);                                             
  }
  if(statecones == HIGH && stateprox == LOW)
  {
//  sendong = "ST1~0~1~" + String(motor) + "~" + String(voltage);
//    sendong = "S1~00"+String(motor)+"~"+String(voltage);
    sendong = "S3~01~"+String(motor)+"~"+String(voltage);
  }
    if(statecones == LOW && stateprox == LOW)
  {
//  sendong = "ST1~1~1~" + String(motor) + "~" + String(voltage);
//    sendong = "S1~10"+String(motor);
    sendong = "S3~11~"+String(motor);
  }
    if(statecones == HIGH && stateprox == HIGH)
  {
//  sendong = "ST1~0~0~" + String(motor) + "~" + String(voltage);
//    sendong = "S1~01"+String(motor);
    sendong = "S3~00~"+String(motor);
  }
  delay(50);
//  sendong.toCharArray(csendong,16);
//  HC12.write(csendong);
  HC12.println(sendong);
//  Serial.println(sendong);
}

void kondisi()
{
  time_t t; 
  t=RTC.get();
  Serial.println("ga masuk ke while");
 // delay(100);
  while ( HC12.available())
 {
  char c = HC12.read();
  s+=c;
 } 
 delay(20);
 statecones = digitalRead(mgnt); 
 stateprox = digitalRead(prox);  
 Serial.println(s);
 if(s.startsWith("Motor"))
 {
  pjg = s.length()-1;
  motor = s.substring(0,7);  
  Serial.println(motor);
  if (smpn != motor)
  {
   adamtr = 1; 
  }
  if(smpn == motor)
  {
    adamtr = 0;
  } 
  smpn = motor;
 }
 if(stateprox == LOW || adamtr == 1 || statecones == LOW)
   {
    kirim();
    Serial.println("kirim");
   // adamtr = 0;
   }
    delay(50);
    motor="";
    s="";
}
