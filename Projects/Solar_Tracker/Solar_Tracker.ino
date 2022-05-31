#include<Servo.h>//initialize servo library
int t,b,r,l;//variables to store ldr values
Servo s1;//servo1
Servo s2;//servo2
int pos=90,pos1=90; //initial positions for servo1 and servo2
const int d=100;//sensitivity
int a,b1,d1,d2;//a and b for direction control

void setup(){
  pinMode(13,OUTPUT);//indicating led at pin 13
  digitalWrite(13,HIGH);//led on
  delay(1000);//delay of 1sec
  digitalWrite(13,LOW);//led off
  delay(1000);
  digitalWrite(13,HIGH);
  delay(1000);
  pinMode(9,OUTPUT);
  analogWrite(9,70);
  
  s1.attach(7);   //left right
  s2.attach(8);    //top bottom
  s1.write(pos);    //initialise servos to 90 degree
  s2.write(pos1);
 
}
void loop(){
  read();     //call read function

  
  while(d1>d && d2>d){   //when all ldr readings are above fixed value d
    if(a==1){             //for s1 and s2 to work simultaneously
      if(pos>20){  
      pos--;}
      s1.write(pos);     //servo1 moves left
      delay(15);
    }else{
      if(pos<160){  
      pos++;}
      s1.write(pos);     //servo1 moves right
      delay(15);
    }
    if(b1==1){
      
      if(pos1>20){  
      pos1--;}
      s2.write(pos1);    //servo1 moves down
      delay(15);
    }else{
      if(pos1<160){  
      pos1++;}
      s2.write(pos1);    //servo1 moves up
      delay(15);
    }
    read();
  }


  
  
  while(d1>d && d2<d){    //s1 to work
    if(a==1){
      if(pos>20){
      pos--;}
      s1.write(pos);
      delay(15);
    }else{
      if(pos<160){
      pos++;}
      s1.write(pos);
      delay(15);
    }
    read();
  }



  while(d1<d && d2>d){     //s2 to work
    if(b1==1){
      if(pos1>20){
      pos1--;}
      s2.write(pos1);
      delay(15);
    }else{
      if(pos1<160){
      pos1++;}
      s2.write(pos1);
      delay(15);
    }
    read();
  }



while(d1<d && d2<d){    //just float
    delay(10);
    read();
  }
  delay(10); 
}


void read(){
  t=analogRead(A4);
  b=analogRead(A5);
  r=analogRead(A2);
  l=analogRead(A3);
  if(l>r){
    d1=l-r;
    a=1;      //setting a=1 for s1 to go left
  }else{
    d1=r-l;
    a=0;      //setting a=0 for s1 to go right
  }
  if(t>b){
    d2=t-b;
    b1=0;     //setting a=0 for s1 to go up
  }else{
    d2=b-t;
    b1=1;     //setting a=0 for s1 to go down
  }
}
