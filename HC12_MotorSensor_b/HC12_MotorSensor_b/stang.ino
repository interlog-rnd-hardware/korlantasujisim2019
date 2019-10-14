void stang()
{
 VSTR = digitalRead(STR);
 VSTL = digitalRead(STL);
  
 str_str=String(VSTR);
 str_stl=String(VSTL);
 
 str_str.toCharArray(cstr,2);
 str_stl.toCharArray(cstl,2);

 footstep();

  if (VSTR == 0 && VSTL==0 && injakr == 0 && injakl == 0)
 {
  digitalWrite(right,LOW);
  digitalWrite(left,LOW);
  detecttrack = 0;
 }
}
