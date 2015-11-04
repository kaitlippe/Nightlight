int logic() {
  switch (stateVar) {
    case (0): // daytime and lights are off
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin2, LOW);
      if (maxBrightness > 0) maxBrightness--;
      if (touched == 1) {
        stateVar = 2;
        touched = 2;
      }
      if (darkState == 1) {
        stateVar = 1;
      }
      break;
    case (1):
      lightVar = 1;
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, HIGH);
      anime01();
      if (touched == 1) {
        stateVar = 2;
        touched = 2;
      } 
      if (darkState == 0) {
        stateVar = 0;
      }
      break;
    case (2):
      lightVar = 1;
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, HIGH);
      anime01();
      if (maxBrightness < 255) maxBrightness++;
      if (touched == 1) {
        stateVar = 3;
        touched = 2;
      }
      break;
    case (3): // touched
      lightVar = 1;
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, HIGH);
      anime02();
      if (touched == 1) {
        stateVar = 0;
        touched = 2;
      }
      break;
  }
}
