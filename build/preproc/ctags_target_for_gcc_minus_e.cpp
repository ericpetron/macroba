# 1 "C:\\Users\\ericp\\Documents\\Arduino\\macroba\\macroba.ino"






int lastButton = 0x0;
int lastClk = 0x1;
int isPressedR = 0x0;
int isPressedB = 0x0;
int isPressedY = 0x0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, 0x2);
  pinMode(4, 0x2);
  pinMode(3, 0x2);
  pinMode(7, 0x0);
  pinMode(6, 0x0);
  pinMode(5, 0x2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readButton(2);
  readButton(3);
  readButton(4);
  readButton(5);
  readEncoder();
}

void readButton(int pin) {

  int pressed = digitalRead(pin);

  if(pressed == 0x0) {
    Serial.print("Button is pressed. Pin is: ");
    Serial.println(pin);
      delay(250);
  }
  // lastButton = pressed;
}

long int modeLastChanged = 0;
int prevClk = 0x1;
void readEncoder() {
  if (digitalRead(5) == 0x0 && millis() - modeLastChanged > 300) {
    modeLastChanged = millis();
    // Do mute or 
  }

  int clk = digitalRead(7);
  if (clk != prevClk && clk == 0x0) {
    int dt = digitalRead(6);
    int delta = dt == 0x1 ? 1 : 2;

    if (delta == 1) {
    Serial.println(
      "R"
    );
    }
    else if (delta == 2) {
      Serial.println(
        "L"
      );
    }

  }
  prevClk = clk;



}
