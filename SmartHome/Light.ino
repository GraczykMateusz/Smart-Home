#define MAX_LIGHTING_POWER 100
#define DEFAULT_LIGHTING_POWER 20

#define TURN_OFF 0

#include <Adafruit_NeoPixel.h>

static uint8_t lightingPower = DEFAULT_LIGHTING_POWER;
static bool isLightTurnOn = false;

void turnOnLights() {
  isLightTurnOn = true;

  for(int i = 0; i < LED_COUNT; ++i) {
    lightUp.setPixelColor(i, lightUp.Color(lightingPower, lightingPower, lightingPower));
    lightDown.setPixelColor(i, lightDown.Color(lightingPower, lightingPower, lightingPower));
  }
  
  lightUp.show();
  lightDown.show();
}

void turnOffLights() {
  isLightTurnOn = false;
  lightingPower = DEFAULT_LIGHTING_POWER;

  for(int i = 0; i < LED_COUNT; ++i) {
    lightUp.setPixelColor(i, lightUp.Color(TURN_OFF, TURN_OFF, TURN_OFF));
    lightDown.setPixelColor(i, lightDown.Color(TURN_OFF, TURN_OFF, TURN_OFF));
  }
  
  lightUp.show();
  lightDown.show();
}

void increaseLightingPower() {
  if(lightingPower < MAX_LIGHTING_POWER && isLightTurnOn) {
    lightingPower += 5;

    for(int i = 0; i < LED_COUNT; ++i) {
      lightUp.setPixelColor(i, lightUp.Color(lightingPower, lightingPower, lightingPower));
      lightDown.setPixelColor(i, lightDown.Color(lightingPower, lightingPower, lightingPower));
    }
    
    lightUp.show();
    lightDown.show();
  }
}

void decreaseLightingPower() {
  if(lightingPower > TURN_OFF && isLightTurnOn) {
    lightingPower -= 5;

    for(int i = 0; i < LED_COUNT; ++i) {
      lightUp.setPixelColor(i, lightUp.Color(lightingPower, lightingPower, lightingPower));
      lightDown.setPixelColor(i, lightDown.Color(lightingPower, lightingPower, lightingPower));
    }
    
    lightUp.show();
    lightDown.show();
  }
}
