void id_motor()
{
  kirimnama += nama;
  kirimnama += mtr;
  kirimnama.toCharArray(id,9);
  //Serial.print(id);
  //Serial.print("~");
  HC12.write(id);
  HC12.write("~");
  //HC12.write("\r\n");
}
