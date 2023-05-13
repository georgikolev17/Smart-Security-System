// C++ code
//
int motionSensor = 0;

int gasSensor = 0;

int temp = 0;

int isOn = 1;

int counter;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(3, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop()
{
  motionSensor = digitalRead(2);
  temp = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -40, 125);
  gasSensor = analogRead(A0);
  int buttonState = digitalRead(3);
  Serial.println(buttonState);

  if (buttonState == 1) {
    isOn = abs(isOn-1);
  }
  if (isOn == 1 && (temp > 40 && gasSensor > 500)) {
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(100); // Wait for 100 millisecond(s)
  }
  if (isOn == 1 && gasSensor > 500) {
    tone(4, 548668578, 200); // play tone 300 (C25 = 548668578 Hz)
    digitalWrite(11, HIGH);
    delay(200); // Wait for 200 millisecond(s)
    digitalWrite(11, LOW);
    delay(200); // Wait for 200 millisecond(s)
  }
  if (isOn == 1 && temp > 40) {
    tone(4, 57079043007393, 200); // play tone 500 (G#41 = 57079043007393 Hz)
    digitalWrite(11, HIGH);
    digitalWrite(13, LOW);
    delay(200); // Wait for 200 millisecond(s)
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
    delay(200); // Wait for 200 millisecond(s)
    digitalWrite(13, LOW);
  }
  if (isOn == 1 && motionSensor == HIGH) {
    for (counter = 0; counter < 15; ++counter) {
      tone(4, 5274, 200); // play tone 100 (E8 = 5274 Hz)
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(12, LOW);
      delay(200); // Wait for 200 millisecond(s)
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(12, HIGH);
      delay(200); // Wait for 200 millisecond(s)
      tone(4, 5274, 200); // play tone 100 (E8 = 5274 Hz)
    }
    digitalWrite(12, LOW);
    noTone(4);
  }
  delay(200);
}