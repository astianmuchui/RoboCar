useint value;
int led = 9;
int en1 = 14;
int in1a = 12;
int in2a = 13;

int en2 = 5;
int in1b = 19;
int in2b = 21;

int reg_speed;
void setup() {
  
  Serial.begin(115200);
  // Serial.println("Initializing.......");
  pinMode(led, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(in1a, OUTPUT);
  pinMode(in2a, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in1b, OUTPUT);
  pinMode(in2b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A0);
  value = map(value,0,1023,0,255);
  analogWrite(led,value);
  // Serial.println(value);
  delay(500);
}

// Turn on motors
void switchOn(){
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);

}

// Turn off the motors

void switchOff(){
  digitalWrite(en1, LOW);
  digitalWrite(en2, LOW);

}

// Forward motion of the robot

void forward(){
  digitalWrite(in1a, HIGH);
  digitalWrite(in1b, LOW);
  digitalWrite(in2a, HIGH);
  digitalWrite(in2b, LOW);
}


// Backward Motion

void backward(){
  digitalWrite(in1a, LOW);
  digitalWrite(in1b, HIGH);

  digitalWrite(in2a, LOW);
  digitalWrite(in2b, HIGH);
}

// Turn right

void TurnRight(){
  digitalWrite(in1a, HIGH);
  digitalWrite(in1b, LOW);

  digitalWrite(in2a, LOW);
  digitalWrite(in2b, HIGH); 
}
// Turn left
void TurnLeft(){
  digitalWrite(in1a, LOW);
  digitalWrite(in1b, HIGH);

  digitalWrite(in2a, HIGH);
  digitalWrite(in2b, LOW); 
}
void FrontRight(){
  forward();
  TurnRight();
  
}
void FrontLeft(){
  forward();
  TurnLeft();
}
void BackRight(){
  backwards();
  TurnRight();
}
void BackLeft(){
  backwards();
  TurnRight();
}
void brake(){
  digitalWrite(in1a,HIGH);
  digitalWrite(in2a,HIGH);
  digitalWrite(in1b,HIGH);
  digitalWrite(in2b,HIGH);
}
void stop(){
  digitalWrite(in1a,LOW);
  digitalWrite(in2a,LOW);
  digitalWrite(in1b,LOW);
  digitalWrite(in2b,LOW);  
}
void regulateSpeed(){
  if(reg_speed<8){
    reg_speed = 0;
  }
  map(reg_speed,0,1023,0,255);
  analogWrite(en1,reg_speed);
  analogWrite(en2,reg_speed);
}
