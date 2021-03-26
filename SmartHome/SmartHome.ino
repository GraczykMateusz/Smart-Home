//Fan
#define FAN 6

//Light
#define LIGHT_UPSTAIRS   7
#define LIGHT_DOWNSTAIRS 8

//Alarm
#define ALARM 9

//Light on
void turnOnLights();
void turnOnLightUpstairs();
void turnOnLightDownstairs();

//Light off
void turnOffLights();
void turnOffLightUpstairs();
void turnOffLightDownstairs();

//Fan on/off
void turnOnFan();
void turnOffFan();

//Fan speed
void increaseFanSpeed();
void decreaseFanSpeed();

//Alarm on/off
void turnOnAlarm();
void turnOffAlarm();

void setup() {
  Serial.begin(9600);
  //Light
  pinMode(LIGHT_UPSTAIRS, OUTPUT);
  pinMode(LIGHT_DOWNSTAIRS, OUTPUT);

  //Fan
  pinMode(FAN, OUTPUT);

  //Alarm
  pinMode(ALARM, INPUT);

  Serial.begin(9600);
}

void loop() {
    switch(userInput()) {
      case 1:
        Serial.println('1');
        break;
      default:
        break;
    }
}
