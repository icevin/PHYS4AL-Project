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

#define CLEAR -1

#define CYCLE_DELAY 150

// Sets display to 0-9, . if invalid, clear if -1 (CLEAR)
void setDisplay(int digit) {
  analogWrite(SEG_PERIOD, 0);
  switch (digit) {
    case CLEAR:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
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
      analogWrite(SEG_PERIOD, 255);
      break;
  }
}

void setOnly(int value) {
  setDisplay(CLEAR);
  switch (value) {
    case 0:
      digitalWrite(SEG_A, HIGH);
      break;
    case 1:
      digitalWrite(SEG_B, HIGH);
      break;
    case 2:
      digitalWrite(SEG_C, HIGH);
      break;
    case 3:
      digitalWrite(SEG_D, HIGH);
      break;
    case 4:
      digitalWrite(SEG_E, HIGH);
      break;
    case 5:
      digitalWrite(SEG_F, HIGH);
      break;
    case 6:
      digitalWrite(SEG_G, HIGH);
  }
}

int readButton(int button) {
  switch (button) {
    case 1:
      return digitalRead(BUTTON_1);
    case 2:
      return digitalRead(BUTTON_2);
    case 3:
      return digitalRead(BUTTON_3);
    case 4:
      return digitalRead(BUTTON_4);
    case 5:
      return digitalRead(BUTTON_5);
    default:
      break;
  }
  return -1;
}

int randDelay = 0;
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

  Serial.println("Testing 7-segment display pin setup...");
  Serial.println("You should see the digits 0-9 appear on your display.");
  Serial.println("Feel free to comment out these lines if you'd like to run tests faster.");
  for (int i = 0; i < 10; i++) {
    setDisplay(i);
    delay(CYCLE_DELAY);
  }

  delay(CYCLE_DELAY);

  Serial.println("Experiment will begin in 3... 2... 1...");

  setDisplay(CLEAR);
  int brightness = 200;
  int fadeAmount = 5;
  int counter = 0;
  for (int i = 0; i < 200; i++) {
    if (i % 10 == 0)
      counter++;

    setOnly(counter % 6);

    analogWrite(SEG_PERIOD, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255)
      fadeAmount = -fadeAmount;

    delay(10);
  }

  setDisplay(CLEAR);

  randomSeed(analogRead(A0));
  randDelay = random(3000, 6000);
  delay(randDelay);
}

// -1 means cleared, 0-9 mean respective digits are being displayed
int currentSegment = -1;

int buttonStates[5] = {LOW, LOW, LOW, LOW, LOW};
int buttonPressed = -1;

bool displayingDigit = false;
int currentDigit = -1;

int trialCount = 0;

long newT;
long oldT;
long deltaT;


void loop() {

  // Poll buttons
  buttonPressed = -1;
  for (int i = 0; i < 5; i++) {
    // NOTE - might have to change this line, depending on how your buttons are connected
    buttonStates[i] = !readButton(i + 1);
    if (buttonStates[i] == HIGH) {
      if (buttonPressed == -1)
        buttonPressed = i + 1;
      else { // Two buttons are being pressed at the same time - invalidate
        buttonPressed = -2;
      }
    }
  }

  //
  if (displayingDigit == false && buttonPressed == -1) {
    // Generate random number from 1-5
    currentDigit = random(1, 4);
    setDisplay(currentDigit);
    oldT = millis();
    displayingDigit = true;
    if(trialCount > 100)
      digitalWrite(SEG_PERIOD, HIGH);
  } else if (displayingDigit == true && buttonPressed == currentDigit) {
    newT = millis();
    setDisplay(CLEAR);x
    if(trialCount > 100)
      digitalWrite(SEG_PERIOD, HIGH);
    
    deltaT = newT - oldT;
    Serial.print(deltaT);
    Serial.print(",");
    Serial.print(currentDigit);
    Serial.println();
    trialCount++;

    displayingDigit = false;
    randDelay = random(1000, 3000);
    delay(randDelay);
  }
}
