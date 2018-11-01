int pumpPin = 8;
int sensorValue = 0;
int percentage = 0;
int smin = 20;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorValue, INPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
   sensorValue = analogRead(A0);
   percentage = convertToPercent(sensorValue);

  printValuesToSerial();

 // Serial.println(sensorValue);
  //Serial.println(percent);
  delay(1000);

  // if the analog value is low enough, turn on the LED:
  if (percentage < smin) {
    digitalWrite(pumpPin, LOW);
  } else {
    digitalWrite(pumpPin, HIGH);
  }

}
int convertToPercent(int value)
{
  int percentValue = 0;
  percentValue = map(value, 1023, 250, 0, 100);
  return percentValue;
}
void printValuesToSerial()
{
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);
  Serial.print("\nPercent: ");
  Serial.print(percentage);
  Serial.print("%");
}
