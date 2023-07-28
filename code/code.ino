int pirPin = 5;    // PIR sensor pin
int buzzerPin = 6; // Buzzer pin
int pirState = LOW; // PIR sensor state
int buzzerState = LOW; // Buzzer state
bool flag=false;
const int trigPin = 10;
const int echoPin = 9;
long duration;
float distance;
//long temp;
int del;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(pirPin, INPUT);   // Set PIR sensor pin as input
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  pinMode(3,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{
  
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  distance= duration*0.03433/2;
 
  if(distance>=2 && distance<25){
    analogWrite(3, 168); // analogWrite(pin,value)
    del=100;
    delay(del);
     fun();
  }
  else if(distance>=25 && distance<50){
    analogWrite(3, 168); // analogWrite(pin,value)
    del=200;
    delay(del);
     fun();
  }
  else if(distance>=50 && distance<75){
    analogWrite(3, 168); // analogWrite(pin,value)
    del=300;
    delay(del);
     fun();
  } 
  else if(distance>=75 && distance<=100){
    analogWrite(3, 168); // analogWrite(pin,value)
    del=400;
    delay(del);
     fun();
  } 
  else{
    analogWrite(3, 0); // analogWrite(pin,value)
    del=500;
    delay(del);
     fun();
  }
  analogWrite(3, 0); // analogWrite(pin,value)
  delay(del);
}

void fun(){
  if(digitalRead(pirPin)==HIGH && flag==false){
    flag=true;
    digitalWrite(LED_BUILTIN, HIGH);// If motion is detected
    analogWrite(buzzerPin, 10);
    delay(200);
     digitalWrite(LED_BUILTIN, LOW);
     analogWrite(buzzerPin, 255);
  }
  else{
    flag=false;
  }
} 
