int ledPin = 9;
int ledBrightness = 125;
int ledState = LOW;

int buttonPin = 2;
int buttonState = LOW;

long randDelay;
long newT;
long oldT;
long deltaT;


// the setup routine runs once when you press reset:
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);

  Serial.println("Prepare. Reaction time measurements will begin shortly!");
  for (int i = 0; i <= 3; i++) {
    analogWrite(ledPin, ledBrightness);
    delay(250);
    analogWrite(ledPin, 0);
    delay(250);
  }
  randomSeed(analogRead(A0));
  randDelay = random(3000, 6000);
  delay(randDelay);
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = !digitalRead(buttonPin);
  
  if (ledState == LOW && buttonState == LOW) {
    analogWrite(ledPin, ledBrightness);
    oldT = millis();
    ledState = HIGH;
  }

  if (ledState == HIGH && buttonState == HIGH) {
    newT = millis();
    analogWrite(ledPin, 0);

    deltaT = newT - oldT;
    Serial.println(deltaT);
    
    ledState = LOW;
    randDelay = random(1000,3000);
    delay(randDelay);
  }
}
