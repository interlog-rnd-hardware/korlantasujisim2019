void track()
{
    if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    //String a;
    //a = String(results.value);
    if (results.value == 0x78B77) //track 1
    {
      //id_motor();
      //rfidrf();
      trekid = 1;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      //HC12.write("1~0");
      //Serial.println("1~0");
      //HC12.write("\r\n");
      digitalWrite(right,LOW);
      digitalWrite(left,HIGH);
    }
    else if (results.value == 0x9A724) //track 2
    {
      //id_motor();
     // HC12.write("0~1");
      //Serial.println("0~1");
      trekid = 2;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      //HC12.write("\r\n");
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
    }
        else if (results.value == 0x3C5BB) //track 3
    {
      //id_motor();
     // HC12.write("0~1");
      //Serial.println("0~1");
      trekid = 3;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      //HC12.write("\r\n");
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
    }
        else if (results.value == 0x1E2DD) //track 4
    {
      //id_motor();
     // HC12.write("0~1");
      //Serial.println("0~1");
      trekid = 4;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      //HC12.write("\r\n");
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
    }
        else if (results.value == 0xB9921) //track 5
    {
      //id_motor();
     // HC12.write("0~1");
      //Serial.println("0~1");
      trekid = 5;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      //HC12.write("\r\n");
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
    }
    else
    {
      
      //id_motor();
      //rfidrf();
      //HC12.write("0~0");
      //Serial.println("0~0");
      trekid = 0;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      HC12.write(ctrek);
      HC12.write("\r\n");H
    }
    irrecv.resume();
  }
  else
  {
     //HC12.write("\r\n");
    //id_motor();
    //rfidrf();
    //Serial.println("0~0");
    //HC12.write(ctrek);
   // HC12.write("\r\n");
  }
}
