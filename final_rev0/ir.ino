void ir()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    //String a;
    //a = String(results.value);
    if (results.value == 0x68B92)
    {
      //id_motor();
      //rfidrf();
      tolehr = 1;
      str_tolehr = String(tolehr);
      str_tolehr.toCharArray(ctolehr,2);
      HC12.write(ctolehr);
      //Serial.println("1~0");
      //HC12.write("\r\n");
      digitalWrite(right,LOW);
      digitalWrite(left,HIGH);
      HC12.write("~");
    }
    else if (results.value == 0x68B77)
    {
      //id_motor();
     // HC12.write("0~1");
      //Serial.println("0~1");
      tolehl= 1;
      str_tolehl = String(tolehl);
      str_tolehl.toCharArray(ctolehl,2);
      HC12.write(ctolehl);
      HC12.write("~");
      //HC12.write("\r\n");
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
    }
    else
    {
      HC12.write(ctolehr);
      HC12.write("~");
      HC12.write(ctolehl);
      HC12.write("~");
      //Serial.println("0~0");
      //HC12.write(cinfrared);
    }
    irrecv.resume();
  }
  else
  {
    //id_motor();
    //rfidrf();
    //Serial.println("0~0");
    //HC12.write(ctolehr);
    //HC12.write("~");
    //HC12.write(ctolehl);
    //HC12.write("~");
    //HC12.write("\r\n");
  }
 
}
