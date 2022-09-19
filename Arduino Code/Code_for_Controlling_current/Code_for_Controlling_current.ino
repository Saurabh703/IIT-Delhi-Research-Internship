#define pwmPin 11

int val;
void setup() {
  // put your setup code here, to run once:
  digitalWrite(pwmPin, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A0) / 4;
  analogWrite(pwmPin, val);
  delay(100);
}
