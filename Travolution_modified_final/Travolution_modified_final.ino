#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX
const int strt=2;    
const int alc=3;
const int ls=4;
const int rly1=5;  
const int rly2=6;
const int buzz=7;  
char x=0;   
void setup()
{
  pinMode(strt,INPUT);
  pinMode(alc,INPUT);   
  pinMode(ls,INPUT);   
  pinMode(rly1,OUTPUT);
  pinMode(rly2,OUTPUT);  
  pinMode(buzz,OUTPUT);    
  Serial.begin(9600);  
  mySerial.begin(1200);
  Serial.println("welcome \n");   
  digitalWrite(strt,HIGH);
  digitalWrite(ls,HIGH);  
  digitalWrite(rly1,LOW);
  digitalWrite(rly2,LOW);
  digitalWrite(buzz,LOW);
  delay(1000);       
  agn:
  if(digitalRead(strt)==HIGH)
  {
  if(digitalRead(alc)==HIGH)
  {
  goto agn;      
  }
  goto agn;    
  }
  digitalWrite(rly1,HIGH);
  digitalWrite(rly2,LOW);  
  digitalWrite(buzz,HIGH);   
}
void loop()
{
home:
  if(digitalRead(alc)==HIGH)
  {
  digitalWrite(rly1,LOW);  
  digitalWrite(rly2,LOW);
wait:  
  if(digitalRead(strt)==HIGH)
  {
  goto wait;    
  }  
  digitalWrite(rly1,HIGH);  
  digitalWrite(rly2,LOW);
  goto home;
  }
  if(digitalRead(ls)==LOW)
  {  
  digitalWrite(rly1,LOW);  
  digitalWrite(rly2,LOW);  
  Serial.println("ALERT PLEASE,ACCIDENT OCCURED TO VEH123\n");  
  goto wait;  
  }
 chk:
  if(mySerial.available()>0)  // Send data only when you receive data:
  {
    x = mySerial.read();      //Read the incoming data and store it into variable data
    if(x == 'Z')            
    {
  digitalWrite(rly1,LOW);
  digitalWrite(rly2,HIGH);
  Serial.println("ALERT PLEASE,ZONE RESTRICTION BEGINS\n");    
  mySerial.end();          
  delay(1000);
  mySerial.begin(1200);
  goto home;  
    }
    if(x == 'N')            
    {
  digitalWrite(rly1,HIGH);
  digitalWrite(rly2,LOW);
  Serial.println("ALERT PLEASE,ZONE RESTRICTION ENDS\n");     
  mySerial.end();  
  delay(1000);
  mySerial.begin(1200);  
  goto home;
    }
    if(x == 'H')            
    {
  digitalWrite(buzz,LOW);
  Serial.println("ALERT PLEASE,HORN RESTRICTION\n");     
  mySerial.end();   
  delay(1000);
  mySerial.begin(1200);    
  goto chk;
    }     
 
  }  
 
}
