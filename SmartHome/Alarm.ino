static bool isAlarmOn = false;

void turnOnAlarm() {
  isAlarmOn = true;
}

void turnOffAlarm() {
  isAlarmOn = false;
  
  digitalWrite(RED_ALARM, LOW);
  digitalWrite(GREEN_ALARM, LOW);
}

bool getIsAlarmOn() {
  return isAlarmOn;
}

void scanning() {
  if(isDetectMove()) {
    turnOnRedAlarm(); 
  } else {
    turnOnGreenAlarm();
  }
}

bool isDetectMove() {
  return digitalRead(ALARM);
}

void turnOnRedAlarm() {
  digitalWrite(RED_ALARM, HIGH);
  digitalWrite(GREEN_ALARM, LOW);
}

void turnOnGreenAlarm() {
  digitalWrite(GREEN_ALARM, HIGH);
  digitalWrite(RED_ALARM, LOW);
}
