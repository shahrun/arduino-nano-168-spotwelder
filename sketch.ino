
#define mosfetPin 3
#define switchPin 2
#define poten A0

int buttonState = 0;
int lastbuttonState = 0;
int dly = 0;


void setup() {
  pinMode(mosfetPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(poten,INPUT);
  // put your setup code here, to run once:
}


void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(switchPin);

if(buttonState != lastbuttonState){

if (buttonState == LOW){
digitalWrite(mosfetPin, HIGH);
delay(durationRange());
digitalWrite(mosfetPin, LOW);
delay(1000);
}
delay(50);
}

lastbuttonState = buttonState;
}

//reading input value from potentiometer
int sensorRange(){
  int sensorValue = analogRead(poten);
  sensorValue = map(sensorValue,0,1023,0,300);
  
  return sensorValue;
}

//write pulse duration in milliseconds
int durationRange(){
  int rangeValue = sensorRange();

if (rangeValue > 0 && rangeValue < 25){
  dly = 25;
  }   
else if ( rangeValue > 25 && rangeValue < 50){
  dly = 50;
}
else if ( rangeValue > 50 && rangeValue < 75){
  dly = 75;
}
else if ( rangeValue > 75 && rangeValue < 100){
  dly = 100;
}
else if ( rangeValue > 100 && rangeValue < 125){
  dly = 125;
}
else if( rangeValue > 125 && rangeValue < 150){
  dly = 150;
}
else if( rangeValue > 150 && rangeValue < 175){
  dly = 175;
}
else if( rangeValue > 175 && rangeValue < 200){
  dly = 200;
}
else if( rangeValue > 200 && rangeValue < 225){
  dly = 225;
}
else if ( rangeValue > 225 && rangeValue < 250){
  dly = 250;
}
else if ( rangeValue > 250 && rangeValue < 300){
  dly = 300;
}

return dly;
}
