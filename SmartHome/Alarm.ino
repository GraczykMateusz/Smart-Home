#define ALARM 9

void turnOnAlarm() {
  if(digitalRead(ALARM))
      turnOnLightUpstairs();
}

void turnOffAlarm() {
  
}
