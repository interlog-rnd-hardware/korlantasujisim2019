void Ir_1()
{
  if (irrecv1.decode(&results1)) 
    {
        Serial.println(results1.value, HEX);
        //String a;
        //a = String(results.value);
        if(results1.value == 0x68B92)
        {
          Serial.println("Kanan");
        }
        else if(results1.value == 0x68B77)
        {
          Serial.println("Kiri");
        }
        else
        {
          Serial.println("ga dapat");
        }
        irrecv1.resume();
    }
}
