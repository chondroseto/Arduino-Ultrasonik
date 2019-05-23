//define pins number
const int trigPin = 10;
const int echoPin = 11;
const int LEDY = 13;
const int LEDR = 12;
const int piezo = 9;

//define variables
long duration;
int distance;
int bts = 1000;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin,OUTPUT); //sets the trigpin as a output
pinMode(echoPin, INPUT);//sets the echopin as an input
Serial.begin(9600);//starts the serial couminaction
}

void loop() {
  // put your main code here, to run repeatedly:
//clear the trigpin
digitalWrite(trigPin,LOW);
delayMicroseconds(2);

// sets the trigpin on high state for 10 micro second
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

//read the echopin
duration = pulseIn(echoPin, HIGH);
//calculating the distance
distance = duration*0.034/2;

if(distance>=bts){
    digitalWrite(LEDY,HIGH);
    digitalWrite(LEDR,LOW);
    noTone(piezo);
  }
  else{
    digitalWrite(LEDY,LOW);
    digitalWrite(LEDR,HIGH);
    tone(piezo,15);
    delay(100);}

//print the distance on the serial monitor
Serial.print("Distance : ");
Serial.print(distance);
Serial.println(" cm");
}
