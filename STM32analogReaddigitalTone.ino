
int sensorPin = PA0;   // Select the input pin for the potentiometer
int sensorValue = 0; // Variable to store the value coming from the sensor
int i, j, k, jj = 0;
int ledPin = PC13;
int piezzo = PC14;
boolean trump;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(piezzo, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  i = i + 1;
  sensorValue = analogRead(sensorPin);
  if (i == 1)
  {
    jj = sensorValue;
  }

  if (i == 2)
  {
    k = sensorValue;
  }
  if  (((k - jj) >= 220) or ((jj - k) >= 220 ))
  {
    tone(piezzo, sensorValue);
    trump = false;
  }
  if  ((((k - jj) >= 70) or ((jj - k) >= 70 )) and (trump = true))
  {
    tone(piezzo, sensorValue);
  }

  delay(10);
  //Serial.println(sensorValue);
  Serial.print(i);
  Serial.print(",");
  Serial.print(jj);
  Serial.print(",");
  Serial.println(k);
  noTone(ledPin);
  noTone(piezzo);

  digitalWrite(piezzo, LOW);
  delay(10);
  if (i == 2)
  {
    i = 0;

  }
}
