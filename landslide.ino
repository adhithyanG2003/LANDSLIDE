#include <SoftwareSerial.h>
SoftwareSerial mySerial(3,2);
SoftwareSerial sim800l(3,2);
int vib = 6;
int rain=A1;
int mos=A0;
int angle=9;
unsigned int v ,r,m,a;

void setup() {
    Serial.begin(9600);
    sim800l.begin(9600);
    pinMode(vib, INPUT);
    pinMode(rain, INPUT);
    pinMode(mos, INPUT);
    pinMode(angle, INPUT);

}

void loop() {
    v = digitalRead(vib);
    Serial.println("vibration=");
    Serial.println(v);
    r= analogRead(rain);
    Serial.println("rain level=");
    Serial.println(r);
    m = analogRead(mos);
    Serial.println("moisture=");
    Serial.println(m);
    a = digitalRead(angle);
    Serial.println("angle");
    Serial.println(a);

if (v==1)                                //VIBRATION DETECTED
{
    Serial.println("vibration is high");
    delay(50);
    VibrateSMS();                          
    delay(6000);
}
else
{ 
     Serial.println("vibration is not high");
     delay(50);
     }
     if (sim800l.available()){           
     Serial.write(sim800l.read()); 
     }
   
  if (m<=300)                               //MOISTUR DETECTED
{
    Serial.println("moisture is high");
    delay(50);
    MoistureSMS();                          
    delay(6000);
}
else
{ 
    Serial.println("moisture is not high");
    delay(50);
  }
  if (sim800l.available()){            
    Serial.write(sim800l.read()); 
  }
    if (r>=600)                              //RAIN DETECTED
{
    Serial.println("rain is high");
    delay(50);
    RainSMS();                          
    delay(6000);
}
else
{ 
    Serial.println("rain is not high");
    delay(50);
    }
    if (sim800l.available()){           
      Serial.write(sim800l.read()); 
    }
if (r==1)                                //LANDSLIDE DETECTOED
{
    Serial.println("landslide ");
    delay(50);
    LandslideSMS();                                                  
    delay(6000);
}
else
{ 
    Serial.println("no land slide");
    delay(50);
  }

  if (sim800l.available()){            
    Serial.write(sim800l.read()); 
  }}
void VibrateSMS()
{
  Serial.println("Vibration SMS Sending ...");             
  sim800l.print("AT+CMGF=1\r");                  
  delay(100);
  sim800l.print("AT+CMGS=\"+918838287247\"\r");  
  delay(500);
  sim800l.print("Security Alart.....!!!!!!! VIBRATON IS HIGH.....MOVE AWAY ");     
  delay(500);
  sim800l.print((char)26);
  delay(500);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(500);

}

void RainSMS()
{
  Serial.println("Rain SMS Sending ...");             
  sim800l.print("AT+CMGF=1\r");                  
  delay(100);
  sim800l.print("AT+CMGS=\"+919655260123\"\r"); 
  delay(500);
  sim800l.print("Security Alart.....!!! RAIN IS ABOVE THE LANDS LIMIT TO RESIST!!! ");  
  delay(500);
  sim800l.print((char)26);
  delay(500);
  sim800l.println();
  Serial.println("TEXT SENT SUCCESSFULLY");
  delay(500);

}

void LandslideSMS()
{
  Serial.println("LANDSLIDE SMS SENDING...");              
  sim800l.print("AT+CMGF=1\r");                 
  delay(100);
  sim800l.print("AT+CMGS=\"+919655260123\"\r"); 
  delay(500);
  sim800l.print("Security Alart.....!!! THE LMRA1247 CONNECTED!! LANDSLIDE ALART!! ");     
  delay(500);
  sim800l.print((char)26);
  delay(500);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(500);

}

void MoistureSMS()
{
  Serial.println("Sending SMS...");              
  sim800l.print("AT+CMGF=1\r");                   
  delay(100);
  sim800l.print("AT+CMGS=\"+919655260123\"\r");  
  delay(500);
  sim800l.print("Security Alart.....!!! MOISTURE CONTENT IN LAND IS HIGH!!! ALART ");      
  delay(500);
  sim800l.print((char)26);
  delay(500);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(500);

}
