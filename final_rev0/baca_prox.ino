void baca_prox()
{

 VPDR = digitalRead(PDR);
 VPDL = digitalRead(PDL);
 VSTR = digitalRead(STR);
 VSTL = digitalRead(STL);
  
 str_pdr=String(VPDR);
 str_pdl=String(VPDL);
 str_str=String(VSTR);
 str_stl=String(VSTL);
 
 str_pdr.toCharArray(cpdr,2);
 str_pdl.toCharArray(cpdl,2);
 str_str.toCharArray(cstr,2);
 str_stl.toCharArray(cstl,2);
  HC12.write("~");
  HC12.write(cpdr); 
  HC12.write(","); 
  HC12.write(cpdl); 
  HC12.write(","); 
  HC12.write(cstr); 
  HC12.write(","); 
  HC12.write(cstl); 
  HC12.write("~");
  //HC12.write("\r\n");
  
  

 // Serial.print(VPDR); Serial.print(","); 
  //Serial.print(VPDL); Serial.print(","); 
 // Serial.print(VSTR); Serial.print(","); 
  //Serial.print(VSTL); Serial.print(","); 

//  SPS += VPDR; SPS +=", ";
//  SPS += VPDL; SPS +=", ";
//  SPS += VSTR; SPS +=", ";
//  SPS += VSTL; 

  /*if (VPDR == 1)
  {
   
  }

  if (VPDR == 0)
  {
    
  }

  if (VSTR == 1)
  {
    
  }

  if (VSTL == 0)
  {
    
  }*/
}
