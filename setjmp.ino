#include <setjmp.h>

/*
 Link Video: https://drive.google.com/file/d/166aYrY-tHOCWTQP2cpl0kgDqlWp1YwFW/view?usp=sharing
 */
jmp_buf temp;

int val = 0;

#define TRY if ((val = setjmp(temp)) == 0)
#define CATCH(NUM) else if (val == NUM)
#define THROW(NUM) longjmp(temp, NUM)

byte ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte sizeLed;

void setup() {

  Serial.begin(9600);
  sizeLed = sizeof(ledPin);


  for (int i = 0; i < sizeLed; i++) {
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i], LOW);
  }
  Serial.println(sizeLed);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  val = setjmp(temp);
  while (1) {
    switch (val) {
      case 3:
        tatLed();
        break;
      case 1:
        chopTat();
        break;
      case 2:
        sangDuoi();
        break;
      default:
        BTN_choptat();
        BTN_sangDuoi();
        BTN_tatLed();
        break;
    }
  }

}

void loop() {

}

void BTN_choptat() {
  int ssButton = digitalRead(10);
  if (ssButton == HIGH) {
    for (int i = 0; i < sizeLed; i++) {
      digitalWrite(ledPin[i], LOW);
    }
    THROW(1);
  }
}

void BTN_sangDuoi() {
  int ssButton = digitalRead(11);
  if (ssButton == HIGH) {
    for (int i = 0; i < sizeLed; i++) {
      digitalWrite(ledPin[i], LOW);
    }
    THROW(2);
  }
}

void BTN_tatLed() {
  int ssButton = digitalRead(12);
  if (ssButton == HIGH) {
    THROW(3);
  }
}

void delay1s_check() {
  for (int i = 0; i < 80; i++) {
    BTN_choptat();
    BTN_sangDuoi();
    BTN_tatLed();
    for (int j = 0; j < 8; j++) {
      Serial.println("");
    }
  }
}

void chopTat() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < sizeLed; j++) {
      digitalWrite(ledPin[j], HIGH);
    }
    delay1s_check();
    for (int j = 0; j < sizeLed; j++) {
      digitalWrite(ledPin[j], LOW);
    }
    delay1s_check();
  }
}

void sangDuoi() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < sizeLed; j++) {
      digitalWrite(ledPin[j], HIGH);
      delay1s_check();
      digitalWrite(ledPin[j], LOW);
      delay1s_check();
    }
  }
}

void tatLed() {
  for (int i = 0; i < sizeLed; i++) {
    digitalWrite(ledPin[i], LOW);
  }
  delay1s_check();
}
