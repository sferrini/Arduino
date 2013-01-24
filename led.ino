//Facciamo lampeggiare un led

#define LED 13    // LED collegato al pin 13


void setup()   {                
  pinMode(LED, OUTPUT);     
}


void loop()                     
{
  digitalWrite(LED, HIGH);   // accende il led
  delay(1000);               // aspetta un secondo
  digitalWrite(LED, LOW);    // spenge il led
  delay(1000);               // aspetta un secondo
}
