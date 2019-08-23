   int counter=0;
   int value;
void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  
  pinMode(7, OUTPUT);
  

}

void loop() {
  digitalWrite(7, HIGH);
  int a8 = digitalRead(8);
  int a9 = digitalRead(9);
  int a10 = digitalRead(10);
  int a11 = digitalRead(11);

 
  value = a11*8+a10*4+a9*2+a8*1;
  Serial.println(value);
  if (value==12){
  counter++;
  digitalWrite(7, LOW);
  delay(50);
  digitalWrite(7, HIGH);
  delay(2000);
  Serial.println(counter);
  }
}
  
