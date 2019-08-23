/*
  asamasach
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int ledPin=7;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int s1=0;
int s2=0;
int s3=0;
int s4=0;
int s0=0;
long counter=0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  digitalWrite(ledPin, HIGH);
  // print the results to the Serial Monitor:
  
  Serial.print(sensorValue);
  Serial.print(",");
  

  

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  s0= analogRead(analogInPin);
  s1= analogRead(analogInPin);
  s2= analogRead(analogInPin);
  s3= analogRead(analogInPin);
  s4= analogRead(analogInPin);
  if ( ((s0+s1+s2+s3+s4)/5) > 400 ){
  
  counter++;
  digitalWrite(ledPin, LOW);
  delay(50);
  digitalWrite(ledPin, HIGH);
  delay(700);  
  }
    

  Serial.println(counter);

}
