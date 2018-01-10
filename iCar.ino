/* Tamir Arnesty, Cameron Quan Yin, Dewmi Seneviratna
   Mr. Wong
   January 20, 2017
   A self driving, intelligent train, running Mr. Wong's legendary course, using nothing but one sensor, one LED, and the world's worst motors.
*/

// Use pin to set speed of right motor
int blueMotor = 11;
// Use pin to set speed of left motor
int greenMotor = 10;

//Motor A BLUE SIDE
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B GREEN SIDE
const int motorPin3  = 8; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293

int rightIR = A5; // blue
int middleIR = A4; // orange
int leftIR = A3; // green
String lastDirection = "";

int blueMotor = 11;
int greenMotor = 10;

//Motor A BLUE SIDE
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B GREEN SIDE
const int motorPin3  = 8; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293


//This will run only one time.
void setup() {

  pinMode(blueMotor, OUTPUT);
  pinMode(greenMotor, OUTPUT);
  //Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  analogWrite(blueMotor, 80);
  analogWrite(greenMotor, 80);
  Serial.begin(9600);
}

int checkMiddle() {
  return analogRead(A4);
}

void turnRight() {
  analogWrite(blueMotor, 61);
  analogWrite(greenMotor, 61);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(100);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void turnLeft() {
  analogWrite(blueMotor, 58);
  analogWrite(greenMotor, 58);
  // left
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(100);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void forwards() {
  analogWrite(blueMotor, 60);
  analogWrite(greenMotor, 60);
  // forwards
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void loop() {
  int middle = checkMiddle();
  int line = 925;
  int cur = millis();
  if (middle > line) {
    int pre = millis();
    while (cur - pre < 375 && middle > line) {
      cur = millis();
      middle = checkMiddle();
      forwards();
    }
    while (middle > line) {
      turnLeft();
      middle = checkMiddle();
    }
  }
  else {
    while (middle <= line) {
      middle = checkMiddle();
      turnRight();
    }
  }
}
