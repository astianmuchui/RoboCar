//simple control version

// 

// INITIALIZING VARIABLES
int EN1 = 14;     // MOTOR 1 connections
int IN1A = 12;
int IN1B = 13;

int EN2 = 5;      // MOTOR 2 connections
int IN2A = 19;
int IN2B = 21;

void setup() {
 // put your setup code here, to run once:
Serial.begin(115200);
Serial.println("ROBOT CAR..\n\n");
pinMode(EN1, OUTPUT);  // MOTOR 1 AS OUTPUT
pinMode(IN1A, OUTPUT);
pinMode(IN1B, OUTPUT);

pinMode(EN2, OUTPUT);  // MOTOR 2 AS OUTPUT
pinMode(IN2A, OUTPUT);
pinMode(IN2B, OUTPUT);

Serial.println(" SWITCHING ON ");
Switch_ON();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(" ROBOT CAR MOVING FORWARD...");
  Forward();
  delay(2000);
  Brake();
  //done

  Serial.println(" ROBOT CAR MOVING BACKWARD...");
  Backward();
  delay(2000);
  Brake();
  //done

  Serial.println(" ROBOT CAR MOVING LEFT...");
  Left();
  delay(2000);
  Brake();
  //done

  Serial.println(" ROBOT CAR MOVING RIGHT...");
  Right();
  delay(2000);
  Brake();
  //done

  Serial.println(" ROBOT CAR STOPPED...");
  Brake();
  delay(2000);
  //done

}

// TURN ON MOTORS
void Switch_ON()
{
 digitalWrite(EN1, HIGH );
 digitalWrite(EN2, HIGH );
}

// TURN OFF MOTORS
void Switch_OFF()
{
 digitalWrite(EN1, LOW );
 digitalWrite(EN2, LOW );
} 

// Forward 
void Forward(){
  digitalWrite(IN1A, HIGH); // TURNING MOTOR 1 FORWARD 
  digitalWrite(IN1B, LOW);

  digitalWrite(IN2A, HIGH); // TURNING MOTOR 2 FORWARD 
  digitalWrite(IN2B, LOW);
} 

// BACKWARD
void Backward(){
  digitalWrite(IN1A, LOW); // TURNING MOTOR 1  BACK
  digitalWrite(IN1B, HIGH);

  digitalWrite(IN2A, LOW); // TURNING MOTOR 2  BACK 
  digitalWrite(IN2B, HIGH);
} 

// RIGHT
void Right(){
  digitalWrite(IN1A, HIGH ); // TURNING MOTOR 1  FORWARD
  digitalWrite(IN1B, LOW);

  digitalWrite(IN2A, LOW); // TURNING MOTOR 2  BACKWARD 
  digitalWrite(IN2B, HIGH);
} 

// TURN ROBOT LEFT
void Left(){
  digitalWrite(IN1A, LOW); // TURNING MOTOR 1  BACKWARD
  digitalWrite(IN1B, HIGH);

  digitalWrite(IN2A, HIGH); // TURNING MOTOR 2  FORWAR.D
  digitalWrite(IN2B, LOW);
} 

// BRAKE 
void Brake(){
  digitalWrite(IN1A, LOW); // TURNING MOTOR 1 off  
  digitalWrite(IN1B, LOW);

  digitalWrite(IN2A, LOW); // TURNING MOTOR 2 off 
  digitalWrite(IN2B, LOW);
} 
