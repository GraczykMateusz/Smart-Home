#define ASCII_OFFSET 48

int userInput() {
  if(Serial.available() > 0) {
        return Serial.read() - ASCII_OFFSET;
  }
  else {
    return -1;
  }
}
