int led = 1; //digital pin 1
int interrupt = 2; //digital pin 2 for the switch
volatile byte state = LOW; //initial state for the led
int tempSensor = A1; //analog pin 1

void setup() 
{
  Serial.begin(9600);
  pinMode(tempSensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(interrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt), func, CHANGE); //if the switch is pressed (interrupt), execute : func
}

void loop()
{
  float tempValue = float( analogRead(tempSensor) ) / 1023; 
  tempValue = tempValue * 500;
  Serial.print("temperature = ");
  Serial.print(tempValue);
  Serial.println("degrees");
  delay(3000); //three seconds
}

void func() 
{
  state = !state; //toggle the state of the led whenever the switch is pressed
  digitalWrite(led, state); //apply the state to the led
  Serial.print("pressed") ; 
  if(state==HIGH)
    Serial.println("ON");
  else
    Serial.println("OFF");
}
