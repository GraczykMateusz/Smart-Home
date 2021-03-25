//Fan
#define FAN 6

//Light
#define LIGHT_UPSTAIRS   7
#define LIGHT_DOWNSTAIRS 8

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

void setup() {
  //Light
  pinMode(LIGHT_UPSTAIRS, OUTPUT);
  pinMode(LIGHT_DOWNSTAIRS, OUTPUT);

  //Fan
  pinMode(FAN, OUTPUT);
}

void loop() {
    turnOnLightUpstairs();
}
