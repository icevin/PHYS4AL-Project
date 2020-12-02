#define SEG_A 7
#define SEG_B 8
#define SEG_C A3
#define SEG_D A2
#define SEG_E A1
#define SEG_F 6
#define SEG_G 5
#define SEG_PERIOD 3

#define BUTTON_1 9
#define BUTTON_2 10
#define BUTTON_3 11
#define BUTTON_4 12
#define BUTTON_5 13

int ledBrightness = 125;
int ledState = LOW;

int buttonPin = 2;
int buttonState = LOW;

long randDelay;
long newT;
long oldT;
long deltaT;

void setDisplay(int digit) {
  switch(digit) {
    case 0:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, LOW);
      break;
    case 1:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
    case 2:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;
    case 3:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;
    case 4:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;
    case 5:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;
    case 6:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;
    case 7:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
    case 8:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;
    case 9:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;
    default:
      Serial.println("Error: setDisplay was called with an invalid digit!");
      break;
  }
}


// the setup routine runs once when you press reset:
void setup() {
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  
  pinMode(SEG_PERIOD, OUTPUT);

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  
  Serial.begin(115200);

  analogWrite(SEG_PERIOD, 200);

  int brightness = 200;
  int fadeAmount = 5;

  Serial.println("Prepare. Experiment starting shortly!");
  
  Serial.println("Experiment will begin once dot segment turns completely off.");
  
  for (int i = 0; i < 200; i++) {
      analogWrite(SEG_PERIOD, brightness);

      brightness = brightness + fadeAmount;
      
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
      delay(10);
  }

   for (int i = 0; i < 9; i++) {
      setDisplay(i);
      delay(200);
  }

  randomSeed(analogRead(A0));
  randDelay = random(3000, 6000);
  delay(randDelay);
}

// the loop routine runs over and over again forever:
void loop() {
//  buttonState = !digitalRead(buttonPin);
//  
//  if (ledState == LOW && buttonState == LOW) {
//    analogWrite(ledPin, ledBrightness);
//    oldT = millis();
//    ledState = HIGH;
//  }
//
//  if (ledState == HIGH && buttonState == HIGH) {
//    newT = millis();
//    analogWrite(ledPin, 0);
//
//    deltaT = newT - oldT;
//    Serial.println(deltaT);
//    
//    ledState = LOW;
//    randDelay = random(1000,3000);
//    delay(randDelay);
//  }
}
