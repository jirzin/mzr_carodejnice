// pin for communication with m3 module
const int soundPin = 9;

// pin for driving LEDs
const int pwmPin = 3;

// fade step values
const int pwmStepDown = 2;
const int pwmStepUp = 25;

const int distanceLimit = 1000;

// pwm value
// reversed logic !!!
// 0 = full light
int pwmValue = 1;

// initial value for analog pin
int aValue = 1024;

// global state
// 0 witch is hidden sound is off
// 1 witch is shown sound is on
int globalState = 0;

// sound is playing ?
boolean sound = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(" Hello this is The Witch arduino");

  delay(1000);
  Serial.println("setting pwm output pin");
  pinMode(pwmPin, OUTPUT);
  analogWrite(pwmPin, 255);
  Serial.println("output pwm pins setup ok");

  delay(1000);
  Serial.println("setting sound output pin");
  pinMode(soundPin, LOW);
  Serial.println("sound pin setup ok");

  delay(1000);
  Serial.println("starting main loop");

}

void loop() {
  // put your main code here, to run repeatedly:
  aValue = analogRead(A1);

  if (aValue < distanceLimit) {
    pwmValue = constrain(pwmValue - pwmStepUp, 0, 255);
    sound = true;
  } else {
    pwmValue = constrain(pwmValue + pwmStepDown, 0, 255);
    if (pwmValue == 255) {
      sound = false;
    }
  }

  analogWrite(pwmPin, pwmValue);
  digitalWrite(soundPin, sound);
  
  Serial.print(sound);
  Serial.print(" | ");
  Serial.print(aValue);
  Serial.print(" | ");
  Serial.println(pwmValue);
  
  delay(10);
}
