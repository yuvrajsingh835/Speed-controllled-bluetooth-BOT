// Left motor
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10;

// Right motor
const int IN3 = 11;
const int IN4 = 12;
const int ENB = 5;

int motorSpeed2 = 150;
int motorSpeed1 = 150; 

int buz ;
int i = 0;


void setup() 
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  pinMode(buz, OUTPUT); 

  Serial.begin(9600);
  Serial.println("Enter: F (forward), B (backward), F (right), L (left), S (stop)");
}

void loop() {
 if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'F':
        moveForward();
        Serial.println("Moving Forward");
        break;
      case 'B':
        moveBackward();
        Serial.println("Moving Backward");
        break;
      case 'L':
        turnLeft();
        Serial.println("Turning Left");
        break;
      case 'G':
        turnLeft();
        Serial.println("Turning Front Left");
        break;
      case 'H':
        turnLeft();
        Serial.println("Turning Back Left");
        break;
      case 'R':
        turnRight();
        Serial.println("Turning Right");
        break;
      case 'I':
        turnRight();
        Serial.println("Turning Front Right");
        break;
      case 'J':
        turnRight();
        Serial.println("Turning Back Right");
        break;
      case 'S':
        stopMotors();
        Serial.println("Stopped");
        break;
      case 'V':
        for(i=1;i<=5;i++)
        {
          digitalWrite(buz, HIGH);
          Serial.println("Buzzer ON !!");
          delay(10);
          digitalWrite(buz, LOW);
        }
      case '1':
        analogWrite(ENA, 20);
        analogWrite(ENB, 20);
        break;
      case '2':
        analogWrite(ENA, 35);
        analogWrite(ENB, 35);
        break;
      case '3':
        analogWrite(ENA, 60);
        analogWrite(ENB, 60);
        break;
      case '4':
        analogWrite(ENA, 100);
        analogWrite(ENB, 100);
        break;
      case '5':
        analogWrite(ENA, 140);
        analogWrite(ENB, 140);
        break;
      case '6':
        analogWrite(ENA, 170);
        analogWrite(ENB, 170);
        break;
      case '7':
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);
        break;
      case '8':
        analogWrite(ENA, 220);
        analogWrite(ENB, 220);
        break;
      case '9':
        analogWrite(ENA, 240);
        analogWrite(ENB, 240);
        break;
      case '0':
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);
        break;
      case 'q':
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        break;
      default:
        Serial.println();
        break;
    }
  }
}

// Movement functions
void moveBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorSpeed1);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, motorSpeed2);
}

void moveForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, motorSpeed1);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, motorSpeed2);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 120);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 120);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 120);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 120);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}