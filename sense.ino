int touchSense() { // a function to check the touch sensor and return the result
  long start = millis();
  long touchVar =  cs_4_2.capacitiveSensor(30);
  delay(50);
  switch (touched) {
    case 0:
      if (touchVar >= 450) touched = 1;
      break;
    case 1:
      break;
    case 2:
      if (touchVar < 450) touched = 0;
      break;
  }
}

int darkSense() {
  int darkVar = analogRead(A0);

  if (darkVar <= 80) {
    darkState = 1;
  } else {
    darkState = 0;
  }
}