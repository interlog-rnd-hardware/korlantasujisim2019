void Ir_2()
{
  if (irrecv2.decode(&results2)) 
    {
        Serial.println(results2.value, HEX);
        //String a;
        //a = String(results.value);
        if(results2.value == 0x68B92)
        {
          Serial.println("Kanan222");
        }
        else if(results2.value == 0x68B77)
        {
          Serial.println("Kiri222");
        }
        else
        {
          Serial.println("ga dapat222");
        }
        irrecv2.resume();
    }
}
