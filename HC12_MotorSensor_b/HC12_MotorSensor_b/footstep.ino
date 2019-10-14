void footstep()
{
  pedalr = analogRead(pdr);
  pedall = analogRead(pdl);
  Serial.println(pedall);
  if (pedalr > 20)
  {
    injakr = 0;
  }
  else
  {
    injakr= 1;
  }

  if (pedall > 20)
  {
    injakl = 0;
  }
   else
  {
    injakl= 1;
  }

  str_pdr=String(injakr);
  str_pdl=String(injakl);
 

  str_pdr.toCharArray(cpdr,2);
  str_pdl.toCharArray(cpdl,2);
//  Serial.println(pedalr);
}
