#define FAN 6

#define MAX_FAN_SPEED 255
#define MIN_FAN_SPEED 70

#define TURN_OFF 0

static int fanSpeed = MIN_FAN_SPEED;
static bool isFanTurnOn = false;

void turnOnFan() {
  isFanTurnOn = true;
  analogWrite(FAN, fanSpeed);
}

void turnOffFan() {
  isFanTurnOn = false;
  analogWrite(FAN, TURN_OFF);
}

void increaseFanSpeed() {
  if(fanSpeed < MAX_FAN_SPEED && isFanTurnOn)
    ++fanSpeed;
}

void decreaseFanSpeed() {
  if(fanSpeed > MIN_FAN_SPEED && isFanTurnOn)
    --fanSpeed;
}
