

/*
 * Initial Author: ryand1011 (https://github.com/ryand1011)
 *
 * Reads data written by a program such as "rfid_write_personal_data.ino"
 *
 * See: https://github.com/miguelbalboa/rfid/tree/master/examples/rfid_write_personal_data
 *
 * Uses MIFARE RFID card using RFID-RC522 reader
 * Uses MFRC522 - Library
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
*/

#include <SPI.h>
#include <MFRC522.h>
//#include <Keyboard.h>

#define RST_PIN         6           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above
//#define RST_PIN     9           // Configurable, see typical pin layout above
//#define SS_PIN     10          // Configurable, see typical pin layout above
#define buzzer      8 //buzzer pin ke 8
#define failind     3
#define succind     4

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

//*****************************************************************************************//
void setup() {
 // Keyboard.begin();
  Serial.begin(9600);                                           // Initialize serial communications with the PC
  SPI.begin();                                                  // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card  
  pinMode(failind, OUTPUT);
  pinMode(succind, OUTPUT);
  pinMode(buzzer, OUTPUT);
 // Serial.println(F("Read personal data on a MIFARE PICC:"));    //shows in serial that it is ready to read
}

//*****************************************************************************************//
void loop() {

  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  //some variables we need
  byte block;
  byte len;
  MFRC522::StatusCode status;

  //-------------------------------------------

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

 // Serial.println(F("**Card Detected:**"));

  //-------------------------------------------

 // mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid)); //dump some details about the card

  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));      //uncomment this to see all blocks in hex

  //-------------------------------------------

 // Serial.print(F("Name: "));

 // byte buffer1[18];

 // block = 4;
//  len = 18;

  //------------------------------------------- GET FIRST NAME
  //status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid)); //line 834 of MFRC522.cpp file
 // if (status != MFRC522::STATUS_OK) {
  //  Serial.print(F("Authentication failed: "));
  //  Serial.println(mfrc522.GetStatusCodeName(status));
  //  return;
 // }

 // status = mfrc522.MIFARE_Read(block, buffer1, &len);
 // if (status != MFRC522::STATUS_OK) {
 //   Serial.print(F("Reading failed: "));
 //   Serial.println(mfrc522.GetStatusCodeName(status));
 //   return;
 // }

  //PRINT FIRST NAME
 // for (uint8_t i = 0; i < 16; i++)
  //{
    //if (buffer1[i] != 32)
  //  {
    //  Serial.write(buffer1[i]);
  //  }
  //}
  //Serial.print(" ");

  //---------------------------------------- GET LAST NAME

  byte buffer2[8];
  block = 1;
  len = 18;

  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid)); //line 834
  if (status != MFRC522::STATUS_OK) {
    //Serial.print(F("Authentication failed: "));
    //Serial.println(mfrc522.GetStatusCodeName(status));
    //return 0;
  }

  status = mfrc522.MIFARE_Read(block, buffer2, &len);
  if (status != MFRC522::STATUS_OK) {
    //Serial.print(F("Reading failed: "));
    //Serial.println(mfrc522.GetStatusCodeName(status));
    digitalWrite(failind, LOW);
    digitalWrite(succind, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    //return 0;
  }

  else
  {
    digitalWrite(failind, HIGH);
    digitalWrite(succind, LOW);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
  }

  //PRINT LAST NAME
  for (uint8_t i = 0; i < 7; i++) {
    Serial.write(buffer2[i] );
   // Keyboard.write(buffer2[i] );
    
  }
  Serial.write("\r\n");
    digitalWrite(succind, HIGH);
    digitalWrite(failind, LOW);
  //----------------------------------------

  //Serial.println(F("\n**End Reading**\n"));

  delay(1000); //change value if you want to read cards faster

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
//*****************************************************************************************//
