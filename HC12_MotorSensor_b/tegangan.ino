void bacategangan()
{
  tegangan = analogRead(volt);
  //Serial.println(tegangan);
  tegaki = tegangan/72.2; //1023/15
  str_tegaki = String(tegaki,1);
  str_tegaki.toCharArray(ctegaki,5);

  tegangan1 = analogRead(volt1);
  //Serial.println(tegangan1);
  tegaki1 = tegangan1/70.2; //1023/15
  str_tegaki1 = String(tegaki1,1);
  str_tegaki1.toCharArray(ctegaki1,5);
}
