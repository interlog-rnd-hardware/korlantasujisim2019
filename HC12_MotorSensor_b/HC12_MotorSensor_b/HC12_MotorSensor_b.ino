#include <SPI.h>
//#include <RFID.h>
#include <IRremote.h>
#include <SoftwareSerial.h>
#include <MFRC522.h>

#define RST_PIN 2
SoftwareSerial HC12(11, 10); // HC-12 TX Pin, HC-12 RX Pin
//pin 5 enable prox
//#define enp 5
#define STR  6
#define STL  4
#define SS_PIN 53
#define kamera 25
//pin 11,12,13 utk RFID
#define right 22
#define left  23
//#define lajur A2
#define IRRX_PIN 5
#define volt A0
#define volt1 A3
#define nyalamotor 44
#define buzzer 32

//int IRRX_PIN = 5;
//int STL = A3;
const int pdr = A1;
const int pdl = A2;
int tolkanan = 0;
int VPDR = 0;
int VPDL = 0;
int VSTR = 0;
int VSTL = 0;
int dataserver;
int x=0;
int y=0; 
int trekid= 0;
int tolehr = 0;
int tolehl= 0;
int panjangrfid;
int finis;
int pedall = 0;
int pedalr = 0;
int injakr =0; 
int injakl =0;
int tegangan = 0;
int tegangan1 = 0;
int detecttrack = 0;

float tegaki = 0.0;
float tegaki1 = 0.0;

String kirimnama;
String mtr = "05";
String nama = "Motor_";
String str_pdr;
String str_pdl;
String str_str;
String str_stl;
String str_tegaki;
String str_tegaki1;
String trek;
String str_tolehr;
String str_tolehl;
String kirim;
String fin;
String s;
String rfiddataa;

char id[9];
char cpdr[2] ;
char cpdl[2] ;
char cstr[2] ;
char cstl[2] ;
char ctolehr[2];
char ctolehl[2];
char ctrek[3];
char ckirim[39];
char co;
char crfid[7];
char ctegaki[5];
char ctegaki1[5];

bool bacasensor;

IRrecv irrecv(IRRX_PIN);
decode_results results;

//RFID rfid(SS_PIN, RST_PIN);
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

void(* resetFunc) (void) = 0;
void setup() 
{
  
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);     
//  pinMode(0,OUTPUT);
//  pinMode(5,OUTPUT);
  pinMode(STR, INPUT);
  pinMode(STL, INPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(kamera,OUTPUT);
  pinMode(nyalamotor,OUTPUT);
  pinMode(buzzer,OUTPUT);
//  pinMode(lajur, OUTPUT);
//  pinMode(enp,OUTPUT);
//  digitalWrite(0, HIGH);
//  digitalWrite(5, HIGH);
  digitalWrite(right,LOW);
  digitalWrite(left,LOW);
  digitalWrite(nyalamotor,LOW);
//  digitalWrite(lajur, LOW);
//  digitalWrite(enp,HIGH);
  irrecv.enableIRIn();
  digitalWrite(IRRX_PIN, HIGH); // Optional Internal Pull-up
  SPI.begin();
  mfrc522.PCD_Init();
  tolehr = 0;
  tolehl = 0;
  finis = 0;
  bacasensor= false;
}
void loop() 
{
//  if (bacasensor == true)
//  {
//  if (panjangrfid != 7) //baca rfid dulu
//  {
//    rfiddata();
//    Serial.println("mana kartunya dah");
//    delay(1000);
//    finis = 0;
//  }
//  if (panjangrfid == 7) //proses lanjut kalo udah detect kartu
//    {    
    id_motor();
    //delay(10);
    rfiddata();
    //delay(10);
    ir();
    delay(10);
    stang();
    delay(10);
    bacategangan();
    delay(10);
    senddata();
    delay(10);
    //Serial.println(detecttrack);
    kirimnama  ="";
    str_tolehr ="";
    str_tolehl ="";
    rfiddataa ="";
    trek="";
    kirim="";
   // bacasensor = false;
    }
//  }
//  motorfinish();
//}
