#define MAX_FAN_SPEED 120
#define DEFAULT_FAN_SPEED 80

#define TURN_OFF 0

static uint8_t fanSpeed = DEFAULT_FAN_SPEED;
static bool isFanTurnOn = false;

void turnOnFan() {
  isFanTurnOn = true;
  analogWrite(FAN, fanSpeed);
}

void turnOffFan() {
  isFanTurnOn = false;
  fanSpeed = DEFAULT_FAN_SPEED;
  analogWrite(FAN, TURN_OFF);
}

void increaseFanSpeed() {
  if(fanSpeed < MAX_FAN_SPEED && isFanTurnOn)
    fanSpeed += 5;
    analogWrite(FAN, fanSpeed);
}

void decreaseFanSpeed() {
  if(fanSpeed > TURN_OFF && isFanTurnOn) {
    fanSpeed -= 5;
    analogWrite(FAN, fanSpeed);
  }
}
