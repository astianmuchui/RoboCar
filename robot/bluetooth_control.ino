
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#define PWM1_Ch1    0     //PWM INIT STUFF
#define PWM1_Ch2    1
#define PWM1_Res   8      // Setting speed bounds where 0 is minimum and 255 is maximum
#define PWM1_Freq  5000

// INITIALIZING VARIABLES
int EN1 = 14;     // MOTOR 1 CONNECTIONS 
int IN1A = 12;
int IN1B = 13;

int EN2 = 5;      // MOTOR 2 CONNECTIONS
int IN2A = 19;
int IN2B = 21;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("Shadow_Walker");       //set bluetooth name of your device

  Serial.println("ROBOT CAR..\n\n");
  pinMode(EN1, OUTPUT);  // MOTOR 1 AS OUTPUT
  pinMode(IN1A, OUTPUT);
  pinMode(IN1B, OUTPUT);

  pinMode(EN2, OUTPUT);  // MOTOR 2 AS OUTPUT
  pinMode(IN2A, OUTPUT);
  pinMode(IN2B, OUTPUT);

  Serial.println(" SWITCHING ON and setting speed  ");

  ledcSetup(PWM1_Ch1, PWM1_Freq, PWM1_Res);   // motor 1
  ledcAttachPin(EN1, PWM1_Ch1);


  ledcSetup(PWM1_Ch2, PWM1_Freq, PWM1_Res); // motor 2
  ledcAttachPin(EN2, PWM1_Ch2);

  Motor_Speed(255);  // Initializing motor at highest speed possible -- use this function to set speed 0 - fully standing and 255 - highest speed
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    Serial.println(" ROBOT CAR MOVING FORWARD...");
    Forward();
    delay(200);
    Brake();
    //done

  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Down");
    Serial.println(" ROBOT CAR MOVING BACKWARD...");
    Backward();
    delay(200);
    Brake();

  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    Serial.println(" ROBOT CAR MOVING LEFT...");
    Left();
    delay(200);
    Brake();
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    Serial.println(" ROBOT CAR MOVING RIGHT...");
    Right();
    delay(200);
    Brake();
  }

    if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");

    Serial.println("motor speed set to full speed");
    Motor_Speed(255);  // change speed to full
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
    Serial.println("motor speed set to 80% speed");
    Motor_Speed(200);    // change speed to 200/255
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
    Serial.println("motor speed set to 40% speed");
    Motor_Speed(100);   // change speed to 100/255
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");

    Serial.print("ROBOT CAR TURNED OFF");
    Switch_OFF();       // fully turn off robot till start key is touched
  }



  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
    Serial.print("ROBOT CAR TURNED ON");
    Switch_ON();      // turn on robot

  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  Serial.print('\t');

  /* 
   *  CHALLENGE ASSIGNMENT
   USE CONTROL STATEMENTS TO FILTER DATA AND CONTROL THE ROBOT BY:
   1.) TILTING YOUR PHONES(Accelerometer Mode)                           
   2.) Joystick control                
   
   TIP :
       The values of variables a(angle), b(radius) c&d(X AND Y axes) change as phone is tilted or joystick moved
       Use if statements to move wheels past a certain threshold by calling the created move functions - FORWARD, REVERSE, LEFT, RIGHT, BRAKE ..also feelfree to create your own functions ;)
         NOTE:
         Radius varies from 0-7 where(0 - middle) and (7 - outermost),
         angle varries from 0°- 360° in steps of 15° ,
         X - axis is bound to -6 to 6  and
         Y - axis is bound to -6 to 6  where (X,Y) -> (0,0) indicated middle
            
      
                                                                                         Good Luck
                                                                                         Happy hacking
                                                                                         GM ^ ^  
    */    
    
  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}


// ALL CONTROL FUNCTIONS DOWN BELOW 

// TURN ON MOTORS
void Switch_ON()
{
  digitalWrite(EN1, HIGH );
  digitalWrite(EN2, HIGH );
}

// SET SPEED
void Motor_Speed(int dutyCycle)
{
  ledcWrite(PWM1_Ch1, dutyCycle); // Setting motor 1 speed
  ledcWrite(PWM1_Ch2, dutyCycle);  // Setting motor 2 speed

}

// TURN OFF MOTORS
void Switch_OFF()
{
  digitalWrite(EN1, LOW );
  digitalWrite(EN2, LOW );
}

// Forward
void Forward()
{
  digitalWrite(IN1A, HIGH); // TURNING MOTOR 1 FORWARD
  digitalWrite(IN1B, LOW);

  digitalWrite(IN2A, HIGH); // TURNING MOTOR 2 FORWARD
  digitalWrite(IN2B, LOW);
}

// BACKWARD
void Backward()
{
  digitalWrite(IN1A, LOW); // TURNING MOTOR 1  BACK
  digitalWrite(IN1B, HIGH);

  digitalWrite(IN2A, LOW); // TURNING MOTOR 2  BACK
  digitalWrite(IN2B, HIGH);
}

// RIGHT
void Right()
{
  digitalWrite(IN1A, HIGH ); // TURNING MOTOR 1  FORWARD
  digitalWrite(IN1B, LOW);

  digitalWrite(IN2A, LOW); // TURNING MOTOR 2  BACKWARD
  digitalWrite(IN2B, HIGH);
}

// TURN ROBOT LEFT
void Left()
{
  digitalWrite(IN1A, LOW); // TURNING MOTOR 1  BACKWARD
  digitalWrite(IN1B, HIGH);

  digitalWrite(IN2A, HIGH); // TURNING MOTOR 2  FORWARD
  digitalWrite(IN2B, LOW);
}

// BRAKE
void Brake()
{
  digitalWrite(IN1A, LOW); // TURNING MOTOR 1 off
  digitalWrite(IN1B, LOW);

  digitalWrite(IN2A, LOW); // TURNING MOTOR 2 off
  digitalWrite(IN2B, LOW);
}
