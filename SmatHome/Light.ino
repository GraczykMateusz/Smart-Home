#define LIGHT_UPSTAIRS   7
#define LIGHT_DOWNSTAIRS 8

void turnOnLights() {
  digitalWrite(LIGHT_UPSTAIRS, HIGH);
  digitalWrite(LIGHT_DOWNSTAIRS, HIGH); 
}

void turnOnLightUpstairs() {
  digitalWrite(LIGHT_UPSTAIRS, HIGH);
}

void turnOnLightDownstairs() {
  digitalWrite(LIGHT_DOWNSTAIRS, HIGH); 
}

void turnOffLights() {
  digitalWrite(LIGHT_UPSTAIRS, LOW);
  digitalWrite(LIGHT_DOWNSTAIRS, LOW); 
}

void turnOffLightUpstairs() {
  digitalWrite(LIGHT_UPSTAIRS, LOW);
}

void turnOffLightDownstairs() {
  digitalWrite(LIGHT_DOWNSTAIRS, LOW); 
}
