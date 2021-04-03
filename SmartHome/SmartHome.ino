//Fan
#define FAN 6

//Light
#define LED_COUNT 21
#define LIGHT_UP 7
#define LIGHT_DOWN 12

//Alarm
#define ALARM 8
#define RED_ALARM 9
#define GREEN_ALARM 10

//Garage doors
#define GARAGE_DOORS 3

//Solar tracker
#define SOLAR_TRACKER_UD 5
#define SOLAR_TRACKER_LR 11

//Solar tracker sensors
#define SENSOR_UL A0
#define SENSOR_UR A1
#define SENSOR_DL A2
#define SENSOR_DR A3

#include <Adafruit_NeoPixel.h>
#include <Servo.h>

Adafruit_NeoPixel lightUp = Adafruit_NeoPixel(LED_COUNT, LIGHT_UP, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel lightDown = Adafruit_NeoPixel(LED_COUNT, LIGHT_DOWN, NEO_GRB + NEO_KHZ800);

Servo garageDoors;

Servo solarTracerUD;
Servo solarTracerLR;

//Light on/off
void turnOnLights();
void turnOffLights();

//Lighting power
void increaseLightingPower();
void decreaseLightingPower();

//Fan on/off
void turnOnFan();
void turnOffFan();

//Fan speed
void increaseFanSpeed();
void decreaseFanSpeed();

//Alarm on/off
void turnOnAlarm();
void turnOffAlarm();

//Garage open/close
void openGarage();
void closeGarage();

//Solar panel moves and auto
void trackerMovesLeft();
void trackerMovesRight();
void trackerMovesUp();
void trackerMovesDown();
void trackerMovesAuto();

void setup() {
  Serial.begin(9600);
  
  //Light
  lightUp.begin();
  lightUp.show();
  lightDown.begin();
  lightDown.show();

  //Fan
  pinMode(FAN, OUTPUT);

  //Alarm
  pinMode(ALARM, INPUT);
  pinMode(RED_ALARM, OUTPUT);
  pinMode(GREEN_ALARM, OUTPUT);

  //Garage doors
  garageDoors.attach(GARAGE_DOORS);
  garageDoors.write(0); //this and next lines of code fix noise offset when power up
  delay(150);
  garageDoors.writeMicroseconds(1500);
  garageDoors.detach();

  //Solar tracker --in progress--
  //solarTracerUD.attach(SOLAR_TRACKER_UD);
  //solarTracerLR.attach(SOLAR_TRACKER_LR);

  //Sensors
  pinMode(SENSOR_UL, INPUT);
  pinMode(SENSOR_UR, INPUT);
  pinMode(SENSOR_DL, INPUT);
  pinMode(SENSOR_DR, INPUT);
}

void loop() {
  switch (userInput()) {
    case 0:
      Serial.println("0");
      turnOnLights();
      break;
    case 1:
      Serial.println("1");
      turnOffLights();
      break;
    case 2:
      Serial.println("2");
      turnOnFan();
      break;
    case 3:
      Serial.println("3");
      turnOffFan();
      break;
    case 4:
      Serial.println('4');
      turnOnAlarm();
      break;
    case 5:
      Serial.println('5');
      turnOffAlarm();
      break;
    case 6:
      Serial.println('6');
      openGarage();
      break;
    case 7:
      Serial.println('7');
      closeGarage();
      break;
    case 8:
      Serial.println('8');
      trackerMovesLeft();
      break;
    case 9:
      Serial.println('9');
      trackerMovesRight();
      break;
    case 10:
      Serial.println("10");
      trackerMovesAuto();
      break;
    case 11:
      Serial.println("11");
      trackerMovesUp();
      break;
    case 12:
      Serial.println("12");
      trackerMovesDown();
      break;
    case 13:
      Serial.println("13");
      increaseLightingPower();
      break;
    case 14:
      Serial.println("14");
      decreaseLightingPower();
      break;
    case 15:
      Serial.println("15");
      increaseFanSpeed();
      break;
    case 16:
      Serial.println("16");
      decreaseFanSpeed();
      break;
    default:
      break;
  }

  //Alarm - continuous scanning when is ON
  if(getIsAlarmOn()) {
    scanning();
  }
}
