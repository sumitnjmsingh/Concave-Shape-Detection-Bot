#define ENA2 3
#define ENA1 5
#define in3 7
#define led 13
#define in4 4
#define in1 8
#define in2 12
#define trig_pin1 A2
#define trig_pin2 A4
#define echo_pin1 A3
#define echo_pin2 A1
long distance1;
long distance2;
long duration1;
long duration2;
int speed1=200;
int speed2=100;
void setup() {
  // put your setup code here, to run once:
pinMode(ENA1,OUTPUT);
pinMode(ENA2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(led,OUTPUT);
pinMode(trig_pin1,OUTPUT);
pinMode(trig_pin2,OUTPUT);
pinMode(echo_pin1,INPUT);
pinMode(echo_pin2,INPUT);
pinMode(in1,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(in2,OUTPUT);
Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
digitalWrite(trig_pin1,LOW);
delayMicroseconds(200);
digitalWrite(trig_pin1,HIGH);
delayMicroseconds(10);
digitalWrite(trig_pin1,LOW);

duration1=pulseIn(echo_pin1,HIGH);

distance1=duration1*0.017;
Serial.print("Distance1: ");
Serial.println(distance1);


digitalWrite(trig_pin2,LOW);
delayMicroseconds(200);
digitalWrite(trig_pin2,HIGH);
delayMicroseconds(10);
digitalWrite(trig_pin2,LOW);

duration2=pulseIn(echo_pin2,HIGH);

distance2=duration2*0.017;
Serial.print("Distance2: ");
Serial.println(distance2);
  
 if((distance1>=20) &&  (distance2<=10)){
 digitalWrite(in1,HIGH);
 digitalWrite(in4,LOW);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
 analogWrite(ENA1,speed1);
 analogWrite(ENA2,speed1);
 digitalWrite(led,LOW);
 }
 else if((distance1>=30) && (distance2>10)){
 digitalWrite(in1,HIGH);
 digitalWrite(in4,LOW);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
//  analogWrite(ENA1,170);
//  analogWrite(ENA2,100);
 digitalWrite(led,LOW);
while(distance2>10){
 analogWrite(ENA1,210);
 analogWrite(ENA2,90);
 digitalWrite(trig_pin2,LOW);
delayMicroseconds(200);
digitalWrite(trig_pin2,HIGH);
delayMicroseconds(10);
digitalWrite(trig_pin2,LOW);

duration2=pulseIn(echo_pin2,HIGH);

distance2=duration2*0.017;
 
 }
}
else if((36<=distance1<40) &&  (distance2<=10)){
digitalWrite(in1,LOW);
digitalWrite(in4,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
// while(distance2>10){
// analogWrite(ENA1,100);
// analogWrite(ENA2,speed1);
digitalWrite(led,HIGH);
while(distance1<40){
analogWrite(ENA1,70);
analogWrite(ENA2,200);  
digitalWrite(trig_pin2,LOW);
delayMicroseconds(200);
digitalWrite(trig_pin2,HIGH);
delayMicroseconds(10);
digitalWrite(trig_pin2,LOW);

duration1=pulseIn(echo_pin2,HIGH);
distance1=duration1*0.017;

}
delay(1000);

// analogWrite(ENA1,speed1);
// analogWrite(ENA2,speed1); 
}
delay(100);}


