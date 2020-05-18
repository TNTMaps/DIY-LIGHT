int ledPin = 12; 
int sensorPin = 2;

int sensorValue;
int lastState = HIGH;

long lastBounce = 0;

long bounceDelay = 50;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  if(sensorValue == lastState)
  {
    lastBounce = millis();
  }
  if((millis()-lastBounce)>bounceDelay)
  {
    lastState = sensorValue;
  }
  digitalWrite(ledPin, lastState);
  Serial.println(sensorValue);
  delay(500);
}
