#include <SoftwareSerial.h>
SoftwareSerial HC12(11, 10); // HC-12 TX Pin, HC-12 RX Pin
#define setPin 6
#define kiri 24
#define kanan 23
String respon,respon1,respon2,respon3,respon4,respon5,finish,belok,s,sub;
int panjang,panjang1,panjang2,panjang3,panjang4,panjang5;
bool m1,m2,m3,m4,mm1,mm2,mm3,mm4,m5,rc,bkanan,bkiri;
char cc[2];
void setup() 
{
  m3 = false;
  rc = true;
  pinMode(setPin, OUTPUT);
  pinMode(kiri,OUTPUT);
  pinMode(kanan,OUTPUT);
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  digitalWrite(setPin, HIGH);           // HC-12 normal, transparent mode
}
void loop() 
{
  if (rc == true)
  {
    fromserver();
    delay(200);
  }
  if (m3 == true)
  {
    ch12(); //motor 3
    delay(200);
  }
}
void ch12()
{
  String dase;
  digitalWrite(setPin, HIGH);          // Exit AT Command mode
  delay(20);
  while (HC12.available())  // If HC-12 has data
  {      
    char c2 = HC12.read();
    respon2 += c2;
  }
//  delay(50);
//  Serial.println(respon2);
  panjang2 = respon2.length();
  String data2 = respon2.substring(0,29);
  String data3 = respon2.substring(13,42);
  int panjangdata2 = data2.length();
  int panjangdata3 = data3.length();
//  Serial.println(panjang2);
//  Serial.println(respon2);
//  if (panjang2 == 31)
  if (respon2.startsWith("Motor_05"))
  {
    Serial.println(data2);
  }//  if(panjang2 == 63 && respon2.startsWith("Motor"))
  else 
  {
//    Serial.println(data3);
  }
//  if (panjang2 == 39 || panjang2 == 35 || panjang2 == 38)
//  {
//    if (panjangdata3 == 29)
//    {
//      Serial.println(data3);
//    }
//  }
//  if (panjang2 == 63 || panjang2 == 31 || panjang2 == 62 || panjang2 == 50)
//  {
//    if (panjangdata2 == 29)
//    {
//      Serial.println(data2);
//    }
//  }
//  delay(100);
  
  rc = true;
  m3 = false;
  respon2="";
}

void fromserver()
{
  
  if (Serial.available()>0)
  {
    s = Serial.readString();
  }
//  else
//  {
//    HC12.write("0");
//  }
  finish = s.substring(0,1);
  finish.toCharArray(cc,2);
  HC12.write(cc);
  belok = s.substring(1,2);
  
  delay(100);
  if (belok == "0") //keduanya mati cuy
  {
    digitalWrite(kiri,LOW);
    delay(100);
    digitalWrite(kanan,LOW);
    delay(100);
  }
   if (belok == "1") //kiri nyala cuy
  {
    //delay(1000);
    digitalWrite(kiri,LOW);
    delay(700);
    digitalWrite(kanan,HIGH);
    delay(100);
  }
  if (belok == "2") //kanan nyala cuy
  {
    //delay(1000); 
    digitalWrite(kanan,LOW);
    delay(700);
    digitalWrite(kiri,HIGH);
    delay(100);
  }
  rc = false;
  m3 = true;
}
