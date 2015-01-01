#include <Servo.h>
#include <SoftwareSerial.h>
#define trigPinFront 13
#define echoPinFront 12

SoftwareSerial Genotronex(10,11); //RX, TX
Servo steering;
Servo eyefront;
Servo eyeback;

int IN1 = 7;
int IN2 = 6;

int pos=0;
char serialA;

void setup(){
  Genotronex.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  steering.attach(4);
  eyefront.attach(2);
  eyeback.attach(8);
  Genotronex.println("Welcome");
}

void loop(){
  while(Genotronex.available() > 0) {
    serialA = Genotronex.read();

    if(serialA == '1'){ //stop
      steering.write(90);
      eyefront.write(90);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
    else if(serialA == '2'){ //backward
      steering.write(90);
      eyefront.write(90);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW); 
    }
    else if(serialA == '3'){ //forward
      steering.write(90);
      eyefront.write(90);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }
    else if(serialA == '4'){ //forward right
      steering.write(135);
      eyefront.write(135);
      digitalWrite(IN1,LOW);//change
      digitalWrite(IN2,HIGH);//chage
    }
    else if(serialA == '5'){ //forward left
      steering.write(45);
      eyefront.write(45);
      digitalWrite(IN1,LOW);//change
      digitalWrite(IN2,HIGH);//change

    }
    else if(serialA == '6'){//back right 
      steering.write(135);
      eyefront.write(135);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW); 
    }
    else if(serialA == '7'){//back right 
      steering.write(45);
      eyefront.write(45);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW); 
    }
    else if(serialA == '8'){
      int duration, distance;
      digitalWrite(trigPinFront, HIGH);
      delay(50);
      digitalWrite(trigPinFront, LOW);

      duration = pulseIn(echoPinFront, HIGH);
      distance = (duration/2)/29.1;

      Genotronex.println(distance);
    }
    else if(serialA == 'f'){
      serialB = Genotronex.read();
      eyefront.write(serialB);
  }
}