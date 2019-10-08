
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define TRIGGERPIN D1
#define ECHOPIN    D2

char auth[] = "e3746b44808f49b79c55677bd77534a4"; // Kode dari Blynk yang di kirim ke email
char ssid[] = "zzzz";
char pass[] = "1357908642";

void setup()
{
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Serial.begin(9600);
  pinMode(D3,OUTPUT);
  
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("Cm");
  Blynk.virtualWrite(V2, distance);
   
  Blynk.run();
  delay(1500);  
    
 if (distance>= 13){
 digitalWrite(D3,HIGH);
  }
 else if (distance<=4){
 digitalWrite(D3, LOW);
  }
  else {
  }
  
   

}
