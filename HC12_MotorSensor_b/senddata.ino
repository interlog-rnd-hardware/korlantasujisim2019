void senddata()
{
  kirim = "<" + nama + 
          mtr + "~" + 
          crfid + "~" + 
          ctolehr + "~" + 
          ctolehl + "~" + 
          cpdr + "," + 
          cpdl + "," + 
          cstr + "," + 
          cstl + "~" + 
          trekid + "~" +
          ctegaki+ "~" + 
          ctegaki1 + 
                  ">"; // + "\r\n";
  kirim.toCharArray(ckirim,43);
  HC12.write(ckirim);
  Serial.println(ckirim);
  rfiddataa ="";
  trek="";
  kirim="";
  delay(80);
}
