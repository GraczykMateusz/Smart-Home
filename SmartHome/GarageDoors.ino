#include <Servo.h>

void openGarage() {
  garageDoors.attach(GARAGE_DOORS);
  
  garageDoors.write(180);
  delay(300);
  garageDoors.writeMicroseconds(1500);

  garageDoors.detach();
}

void closeGarage() {
  garageDoors.attach(GARAGE_DOORS);

  garageDoors.write(0);
  delay(250);
  garageDoors.writeMicroseconds(1500);

  garageDoors.detach();
}
