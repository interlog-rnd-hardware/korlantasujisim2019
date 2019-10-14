void track()
{
    if (irrecv.decode(&results))
  {
    if (results.value == 0x78B77) //track 1
    {
      trekid = 1;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      digitalWrite(right,LOW);
      digitalWrite(left,HIGH);
    }
    else if (results.value == 0x9A724) //track 2
    {
      trekid = 2;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
    }
    else if (results.value == 0x3C5BB) //track 3
    {
      trekid = 3;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
    }
        else if (results.value == 0x1E2DD) //track 4
    {
      trekid = 4;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      //HC12.write("\r\n");
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
    }
        else if (results.value == 0xB9921) //track 5
    {
      trekid = 5;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
    }
    else
    {
      trekid = 0;
    }
    irrecv.resume();
  }
  else
  {
     trek=String(trekid);
     trek.toCharArray(ctrek,3);
  }
}
