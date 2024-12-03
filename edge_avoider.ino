#define MLa 6 //left motor 1st pin
#define MLb 9 //left motor 2nd pin
#define MRa 10 //right motor 1st pin
#define MRb 11 //right motor 2nd pin
#define Sensor 2

void setup()
{
pinMode(Sensor, INPUT);// declaring sensor pin as input pin for Arduino
pinMode(MLa, OUTPUT);// declaring Motors pin as output pin
pinMode(MLb, OUTPUT);
pinMode(MRa, OUTPUT);
pinMode(MRb, OUTPUT);
Serial.begin(9600);
}
void loop()
{
int Sensorin=digitalRead(Sensor);
Serial.println(Sensorin);
delay(100);
if ( Sensorin == LOW) // applying condition
{//forward
analogWrite(MLb, 255);
digitalWrite(MLa, LOW);
analogWrite(MRa, 255);
digitalWrite(MRb, LOW);
Serial.println("Forward");
}
else{//Stop
digitalWrite(MLa, LOW);
digitalWrite(MLb, LOW);
digitalWrite(MRa, LOW);
digitalWrite(MRb, LOW);
Serial.println("Stop");
delay(500);
//backward
digitalWrite(MLa, LOW);
digitalWrite(MLb, HIGH);
digitalWrite(MRa, LOW);
digitalWrite(MRb, HIGH);
Serial.println("Backward");
delay(700);
//Stop
digitalWrite(MLa, LOW);
digitalWrite(MLb, LOW);
digitalWrite(MRa, LOW);
digitalWrite(MRb, LOW);
Serial.println("Stop");
delay(300);
//Rightturn
digitalWrite(MLa, HIGH);
digitalWrite(MLb, LOW);
digitalWrite(MRa, LOW);
digitalWrite(MRb, LOW);
Serial.println("Right");
delay(600);
}
}
