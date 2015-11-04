int anime01() { // a function to reduce the brightness of leds so they fade out.
  int currentTime = millis(); // check the time
  ledsMax[ledState] = 3000;
  if (currentTime - prevLedTime >= ledSpeed) { //if enough time has gone by:
    ledsDir[ledState] = 0;
    ledState++;
    if (ledState == 6) ledState = 0;
    ledsDir[ledState] = 3;
    prevLedTime = currentTime;
  }
}


int anime02() {
  int currentTime = millis();
  if (currentTime - prevLedTime >= ledSpeed) {
    for (int i = 0; i < 6; i++) {
      ledsMax[i] = 1000;
      ledsDir[i] = 1;
    }
    ledSpeed = 1000;
    prevLedTime = currentTime;
  }
}

int updateLED() {
  unsigned long currentMillis = millis();
  if (currentMillis - fadePreviousMillis >= fadeSpeed) {
    for (int i = 0; i < pinCount; i++) {
      switch (ledsDir[i]) {
        case 0: // stay at 0 or fade down to 0
          if (ledsVal[i] > 0) ledsVal[i]--;
          break;
        case 1: // fading up and down - up
          ledsVal[i]++;
          if (ledsVal[i] >= 255) ledsDir[i] = 2;
          break;
        case 2: // fading up and down - down
          ledsVal[i]--;
          if (ledsVal[i] <= 0) ledsDir[i] = 1;
          break;
        case 3: // stay at 255 or fade up to 255
          if (ledsVal[i] < 255) ledsVal[i]++;
          break;
        default:
          Serial.println("default");
          break;
      }
      int x = map(ledsVal[i], 0, 300, 0, maxBrightness);
      analogWrite(leds[i], x);
      //Serial.println(ledsVal[1]);
      fadePreviousMillis = currentMillis;
    }
  }
}