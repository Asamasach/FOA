const int sensor= A0;
const int relay=7;

int sensor_v = 0;        // value read from the pot
int ls_p=0;
int cs_p=0;
long counter=0;
long counter_time=0;
int a8;
int a9;
int a10;
int a11;

  unsigned int pedal_v = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  
}

void loop() {
  digitalWrite(relay, HIGH);
  // print the results to the Serial Monitor:
  sensor_v = analogRead(sensor);
  sensor_v = ( sensor_v + analogRead(sensor) )/2;
  Serial.print("Sensor_v: ");
  Serial.println(sensor_v);


  a8 = digitalRead(8);
  a9 = digitalRead(9);
  a10 = digitalRead(10);
  a11 = digitalRead(11);
  pedal_v = a11*8+a10*4+a9*2+a8*1;
  Serial.print("Pedal_v: ");
  Serial.println(pedal_v);


  

  if ( sensor_v < 200 ) {

  sensor_v = analogRead(sensor);
  sensor_v = ( sensor_v + analogRead(sensor) )/2;
  Serial.print("Sensor_v: ");
  Serial.println(sensor_v);


  a8 = digitalRead(8);
  a9 = digitalRead(9);
  a10 = digitalRead(10);
  a11 = digitalRead(11);
  pedal_v = a11*8+a10*4+a9*2+a8*1;
  Serial.print("Pedal_v: ");
  Serial.println(pedal_v);
 
  if ( pedal_v < 12 /* or pedal_v==13*/ ){
  
  //if (counter != 0 ){
  counter++;
  digitalWrite(relay, LOW);
  delay(50);
  digitalWrite(relay, HIGH);
  Serial.println(counter);
  delay(1000);
  //}
    

  sensor_v = analogRead(sensor);
  sensor_v = ( sensor_v + analogRead(sensor) )/2;
  Serial.print("Sensor_v: ");
  Serial.println(sensor_v);

wait_until_sensor_clear: 
  if ( sensor_v < 200 ) {
  counter_time += 1;
  delay(50);
  /*if ( counter_time > 1200) { 
    // counter_time=0;
    counter_time=0;
    goto next;
  }*/
    sensor_v = analogRead(sensor);
    sensor_v = ( sensor_v + analogRead(sensor) )/2;
    Serial.print("Sensor_v: ");
    Serial.println(sensor_v);
    Serial.print("Waiting time for clearance: ");
    Serial.println(counter_time/20);
    
  goto wait_until_sensor_clear;
  }
  counter_time=0;
  }
  }  
  
}
