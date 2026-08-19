
// L293D #1
#define EN1 5
#define IN1 2
#define IN2 3
#define EN2 6
#define IN3 4
#define IN4 7

// L293D #2
#define EN3 9
#define IN5 8
#define IN6 10
#define EN4 11
#define IN7 12
#define IN8 13

// Motor speed
int speedMotor = 200;

// Setup
void setup() {
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(EN4, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  Serial.begin(9600);

  stopMotors();
  delay(1000);
}

// Forward
void moveForward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);

  analogWrite(EN1, speedMotor);
  analogWrite(EN2, speedMotor);
  analogWrite(EN3, speedMotor);
  analogWrite(EN4, speedMotor);
}

// Backward
void moveBackward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);

  analogWrite(EN1, speedMotor);
  analogWrite(EN2, speedMotor);
  analogWrite(EN3, speedMotor);
  analogWrite(EN4, speedMotor);
}

// Turn Right (Left side forward, Right side backward)
void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);   // Left front forward
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);   // Left back forward
  digitalWrite(IN5, LOW);  digitalWrite(IN6, HIGH);  // Right front backward
  digitalWrite(IN7, LOW);  digitalWrite(IN8, HIGH);  // Right back backward

  analogWrite(EN1, speedMotor);
  analogWrite(EN2, speedMotor);
  analogWrite(EN3, speedMotor);
  analogWrite(EN4, speedMotor);
}

// Turn Left (Left side backward, Right side forward)
void turnLeft() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);  // Left front backward
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);  // Left back backward
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);   // Right front forward
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);   // Right back forward

  analogWrite(EN1, speedMotor);
  analogWrite(EN2, speedMotor);
  analogWrite(EN3, speedMotor);
  analogWrite(EN4, speedMotor);
}

// Alternate Right/Left for a given total duration (turning simulation)
void alternateTurns(unsigned long totalDurationMs, unsigned long stepMs) {
  unsigned long startTime = millis();
  bool goingRight = true;

  while (millis() - startTime < totalDurationMs) {
    if (goingRight) {
      Serial.println("Turning Right");
      turnRight();
    } else {
      Serial.println("Turning Left");
      turnLeft();
    }
    delay(stepMs);
    goingRight = !goingRight;
  }
}


// Stop Motors

void stopMotors() {
  analogWrite(EN1, 0);
  analogWrite(EN2, 0);
  analogWrite(EN3, 0);
  analogWrite(EN4, 0);

  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW); digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW); digitalWrite(IN8, LOW);
}


// Main Program
void loop() {
  // 1. Forward for 30 seconds
  Serial.println("Moving Forward - 30s");
  moveForward();
  delay(30000);
  stopMotors();
  delay(300);

  // 2. Backward for 60 seconds (full minute)
  Serial.println("Moving Backward - 60s");
  moveBackward();
  delay(60000);
  stopMotors();
  delay(300);

  // 3. Right and Left alternating for 60 seconds (turning simulation)
  Serial.println("Alternating Right/Left - 60s");
  alternateTurns(60000, 5000); // switches direction every 5 seconds

  // Stop after completing the task
  stopMotors();
  Serial.println("Task complete");

  // Prevent repeating the task
  while (true) {
    delay(1000);
  }
}