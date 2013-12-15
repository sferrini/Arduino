#include <GSM.h>

int led = 12;

#define PINNUMBER ""

GSM gsmAccess;
GSM_SMS sms;

char senderNumber[20];  

void setup() 
{
  Serial.begin(9600);
    
  pinMode(led,OUTPUT);
  
  while (!Serial)
  {
    ;
  } 

  Serial.println("SMS Messages Receiver");

  boolean notConnected = true;

  while(notConnected)
  {
    if(gsmAccess.begin(PINNUMBER)==GSM_READY)
      notConnected = false;
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }
  
  Serial.println("GSM initialized");
  Serial.println("Waiting for messages");
}

void loop() 
{
  char c;
  
  // If there are any SMSs available()  
  if (sms.available())
  {
    Serial.println("Message received from:");

    sms.remoteNumber(senderNumber, 20);
    Serial.println(senderNumber);
    
    // Any messages starting with # should be discarded
    if(sms.peek()=='#')
    {
      Serial.println("Discarded SMS");
      sms.flush();
    }

    if(sms.peek()=='1')
    {
      Serial.println("ON");
      digitalWrite(led, HIGH);
      sms.flush();
    }

    if(sms.peek()=='2')
    {
      Serial.println("OFF");
      digitalWrite(led, LOW);
      sms.flush();
    }


/*
    // Read message bytes and print them
    while(c=sms.read())
      Serial.print(c);
*/

  sms.flush();
  // Serial.println("MESSAGE NO COMPATIBLE");
  Serial.println("MESSAGE DELETED");
  
  }

  delay(1000);

}
