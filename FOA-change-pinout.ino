const int sensor= A0;
const int relay=11;
const int led=13;

int sensor_v = 0;        // value read from the pot
long counter=0;
long counter_time=0;
int a3;
int a5;
int a7;
int a9;
unsigned int pedal_v = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  
}

void loop() {
  digitalWrite(relay, LOW);

//--------------------check_for_machine_being_on-----------------------
wait_until_machine_on:
  sensor_v = analogRead(sensor);
  sensor_v = ( sensor_v + analogRead(sensor) )/2;
  Serial.print("Sensor_v: ");
  Serial.println(sensor_v);

if ( sensor_v < 30 ) {

  a3 = digitalRead(3);
  a5 = digitalRead(5);
  a7 = digitalRead(7);
  a9 = digitalRead(9);
  pedal_v = a9*8+a7*4+a5*2+a3*1;
  Serial.print("Pedal_v: ");
  Serial.println(pedal_v); 
if (pedal_v==0){
  delay(100);
  a3 = digitalRead(3);
  a5 = digitalRead(5);
  a7 = digitalRead(7);
  a9 = digitalRead(9);
  pedal_v = a9*8+a7*4+a5*2+a3*1;
  Serial.print("Pedal_v: ");
  Serial.println(pedal_v); 
  if (pedal_v==0){
  goto wait_until_machine_on;
  counter=0;
  } 
}
}

//---------------------------------------------------------------------------
  a3 = digitalRead(3);
  a5 = digitalRead(5);
  a7 = digitalRead(7);
  a9 = digitalRead(9);
  pedal_v = a9*8+a7*4+a5*2+a3*1;
  Serial.print("Pedal_v: ");
  Serial.println(pedal_v);



  sensor_v = analogRead(sensor);
  sensor_v = ( sensor_v + analogRead(sensor) )/2;
  Serial.print("Sensor_v: ");
  Serial.println(sensor_v);
  
//-------------is_there_any_fabric?----------------------
  if ( sensor_v < 200 and sensor_v >50 ) {

  a3 = digitalRead(3);
  a5 = digitalRead(5);
  a7 = digitalRead(7);
  a9 = digitalRead(9);
  pedal_v = a9*8+a7*4+a5*2+a3*1;
  Serial.print("Pedal_v: ");
  Serial.println(pedal_v);

//----------------is_pedal_pushed?-----------------------
  if ( pedal_v < 12 and pedal_v > 0 ){

  sensor_v = analogRead(sensor);
  sensor_v = ( sensor_v + analogRead(sensor) )/2;
  Serial.print("Sensor_v: ");
  Serial.println(sensor_v);
  
  if (sensor_v > 30 ){  // this is for start of machine to be sure everythings is alright*/

  
  digitalWrite(relay, HIGH);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(relay, LOW);
  digitalWrite(led, LOW);
  Serial.println(counter);
  delay(100);
  }

counter++;


//-----------------------tp_be_sure_stop_doesn't_effect_counting------------------
wait_until_pedal_clear:  
  a3 = digitalRead(3);
  a5 = digitalRead(5);
  a7 = digitalRead(7);
  a9 = digitalRead(9);
  pedal_v = a9*8+a7*4+a5*2+a3*1;
  Serial.print("Pedal_v: ");
  Serial.println(pedal_v);  

if ( pedal_v < 12 or pedal_v==13 or pedal_v==15 ){
  /*if (counter==1){
    goto next;
  }*/
goto wait_until_pedal_clear;
}
next:
//----------------------------------------------------------------------------------

  sensor_v = analogRead(sensor);
  sensor_v = ( sensor_v + analogRead(sensor) )/2;
  Serial.print("Sensor_v: ");
  Serial.println(sensor_v);


wait_until_sensor_clear: 
  if ( sensor_v < 200 and sensor_v >50  ) {
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
