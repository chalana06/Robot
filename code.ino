
int MotorAip1=7; //Right motor
int MotorAip2=8;
int MotorBip1=9; //Left motor
int MotorBip2=10;

int IR1=12;      //Right sensor
int IR2=13;    //left Sensor

int enablerA = 6;
int enablerB = 5;



void setup() {   
  // put your setup code here, to run once:
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);

  pinMode(enablerA, OUTPUT);
  pinMode(enablerB, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:


//  analogWrite(enablerA, 95);
//  analogWrite(enablerB, 95);
  
  if (digitalRead(IR1)==LOW && digitalRead(IR2)==LOW){
    analogWrite(enablerA, 120);
    analogWrite(enablerB, 120);
    front();
  }else if (digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH){
    stop();
  }else if (digitalRead(IR1)==HIGH && digitalRead(IR2)==LOW){
    analogWrite(enablerA, 170);
    analogWrite(enablerB, 170);
    right();
  }else if (digitalRead(IR1)==LOW && digitalRead(IR2)==HIGH){
    analogWrite(enablerA, 170);
    analogWrite(enablerB, 170);
    left();
  }

}

int front(){
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
//    analogWrite (enA, 200);
//    analogWrite (enB, 200);
//    delay(100);

    return 0;

}


int left(){
    //Tilt robot towards right by stopping the right wheel and moving the left one
    digitalWrite(MotorAip1,LOW);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
//    analogWrite (enA, 150);
//   analogWrite (enB, 200);
 //   delay(100);

   return 0;
}

int right(){

    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
//    analogWrite (enA, 200);
//    analogWrite (enB, 150);
//   delay(100);

   return 0;
  
}


int stop(){
  //Stop both Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
//    delay(100);

 }
