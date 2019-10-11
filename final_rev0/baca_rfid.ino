void rfidrf()
{
    if (rfid.isCard()) {
      if (rfid.readCardSerial()) {
        //id_motor();
        sernum0 = String((rfid.serNum[0]));
        sernum0.toCharArray(csernum0,4);
        HC12.write(csernum0);
        //HC12.write(" ");
        //Serial.print(rfid.serNum[0]);
        //Serial.print(" ");

        sernum1 = String((rfid.serNum[1]));
        sernum1.toCharArray(csernum1,4);
        HC12.write(csernum1);
        //HC12.write(" ");
        //Serial.print(rfid.serNum[1]);
        //Serial.print(" ");

        sernum2 = String((rfid.serNum[2]));
        sernum2.toCharArray(csernum2,4);
        HC12.write(csernum2);
        //HC12.write(" ");
        //Serial.print(rfid.serNum[2]);
        //Serial.print(" ");

        //sernum3 = String((rfid.serNum[3]));
        //sernum3.toCharArray(csernum3,4);
        //HC12.write(csernum3);
        HC12.write(" ");
        //Serial.print(rfid.serNum[3]);
        //Serial.print(" ");

        //sernum4 = String((rfid.serNum[4]));
        //sernum4.toCharArray(csernum4,4);
        //HC12.write(csernum4);
        //HC12.write(csernum4);
        HC12.write("~");
       // HC12.write("\r\n");
       // Serial.println(rfid.serNum[4]);
        
      }
      rfid.halt();
    }
}
