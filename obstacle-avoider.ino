const int trigL = 2;
const int echoL = 3;
const int trigR = 4;
const int echoR = 5;


const int in1 = 8; 
const int in2 = 9;
const int in3 = 10; 
const int in4 = 11;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);

  Serial.begin(9600);
}


float getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 30000); 
  if (duration == 0) return 999; 
  return duration * 0.034 / 2;  
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackwards() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  float leftDist = getDistance(trigL, echoL);
  float rightDist = getDistance(trigR, echoR);


  Serial.print("LEFT: ");
  Serial.print(leftDist);
  Serial.print(" cm\t\tRIGHT: ");
  Serial.print(rightDist);
  Serial.println(" cm");

  if (leftDist > 20 && rightDist > 20) {

    moveForward();
    Serial.println("FORWARD");
    delay(200);
    stopMotors();
    delay(100);
  } 
  else if (leftDist > 20 && rightDist < 20) {

    Serial.println("TURNING LEFT");
    turnLeft();
    delay(400);
    stopMotors();
  }
  else if (leftDist < 20 && rightDist > 20) {
 
    Serial.println("TURNING RIGHT");
    turnRight();
    delay(400);
    stopMotors();
  }
  else if (leftDist < 20 && rightDist < 20) {

    moveBackwards();
    Serial.println("BACKWARD");
    delay(400);
    stopMotors();
  }

  delay(100);
}
