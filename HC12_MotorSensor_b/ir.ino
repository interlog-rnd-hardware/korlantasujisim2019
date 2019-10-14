void ir()
{
  if (irrecv.decode(&results))
  {

    if (results.value == 0x68B92 && tolkanan == 1) //kiri
    {
      tolehr = 1;
      str_tolehr = String(tolehr);
      str_tolehr.toCharArray(ctolehr,2);
      digitalWrite(right,LOW);
      digitalWrite(left,HIGH);
      digitalWrite(nyalamotor,LOW);
      tolkanan = 0;
      digitalWrite(kamera,HIGH);
    }
    else if (results.value == 0x68B77 && detecttrack == 1) // kanan
    {
      tolehl= 1;
      str_tolehl = String(tolehl);
      str_tolehl.toCharArray(ctolehl,2);
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
      digitalWrite(nyalamotor,LOW);
      tolkanan = 1;
    }
    if (results.value == 0x78B77 && detecttrack == 0 ) //track 1
    {
      trekid = 1;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      detecttrack = 1;
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
      delay(50);
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
    }
    else if (results.value == 0x9A724 && detecttrack == 0) //track 2
    {
      trekid = 2;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      detecttrack = 1;
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
      delay(50);
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
    }
    else if (results.value == 0x3C5BB && detecttrack == 0) //track 3
    {
      trekid = 3;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      detecttrack = 1;
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
      delay(50);
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
    }
        else if (results.value == 0x1E2DD && detecttrack == 0) //track 4
    {
      trekid = 4;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      detecttrack = 1;
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
      delay(50);
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
    }
        else if (results.value == 0xB9921 && detecttrack == 0) //track 5
    {
      trekid = 5;
      trek=String(trekid);
      trek.toCharArray(ctrek,3);
      detecttrack = 1;
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
      delay(50);
      buzzer_tone(1);
      delay(50);
      buzzer_tone(0);
    }
    irrecv.resume();
  }
  else
  {
    tolehr = 0;
      str_tolehr = String(tolehr);
      str_tolehr.toCharArray(ctolehr,2);
    tolehl= 0;
      str_tolehl = String(tolehl);
      str_tolehl.toCharArray(ctolehl,2);
  }
 
}
