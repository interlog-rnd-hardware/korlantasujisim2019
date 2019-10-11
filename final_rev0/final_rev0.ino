#include <SPI.h>
#include <RFID.h>
#include <IRremote.h>
#include <SoftwareSerial.h>

SoftwareSerial HC12(3, 4); // HC-12 TX Pin, HC-12 RX Pin

#define SS_PIN 10
#define RST_PIN 9
#define PDR  8
#define PDL  7
#define STR  2
#define right A0
#define left  A1
#define lajur A2
#define SS_PIN 10
#define RST_PIN 9

int IRRX_PIN = 5;
int STL = A3;
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

String kirimnama;
String mtr = "01";
String nama = "Motor_";
String str_pdr;
String str_pdl;
String str_str;
String str_stl;
String sernum0;
String sernum1;            
String sernum2;
String sernum3;
String sernum4;
String trek;
String str_tolehr;
String str_tolehl;

char id[9];
char cpdr[2] ;
char cpdl[2] ;
char cstr[2] ;
char cstl[2] ;
char csernum0[4];
char csernum1[4];
char csernum2[4];            
char csernum3[4];
char csernum4[4];
char ctolehr[2];
char ctolehl[2];
char ctrek[3];

IRrecv irrecv(IRRX_PIN);
decode_results results;

RFID rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);   
  
  pinMode(PDR, INPUT);
  pinMode(PDL, INPUT);
  pinMode(STR, INPUT);
  pinMode(STL, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(lajur, OUTPUT);

  digitalWrite(right,LOW);
  digitalWrite(left,LOW);
  digitalWrite(lajur, LOW);
  
  irrecv.enableIRIn();
  digitalWrite(IRRX_PIN, HIGH); // Optional Internal Pull-up
  SPI.begin();
  rfid.init();
}

void loop() {
  id_motor();  
  delay(50);
  rfidrf();
  delay(50);
  ir();
  delay(50);
  baca_prox();
  delay(50);
  track();
}
