#define ENCODER_CLK 7
#define ENCODER_DT  6
#define ENCODER_SW 5
#define RED 2
#define BLUE 4
#define YELLOW 3
int lastButton = LOW;
int lastClk = HIGH;
int isPressedR = LOW;
int isPressedB = LOW;
int isPressedY = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, INPUT_PULLUP);
  pinMode(BLUE, INPUT_PULLUP);
  pinMode(YELLOW, INPUT_PULLUP);
  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_SW, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readButton(RED);
  readButton(YELLOW);
  readButton(BLUE);
  readButton(ENCODER_SW);
  readEncoder();
}

void readButton(int pin) {
  
  int pressed = digitalRead(pin);

  if(pressed == LOW) {
    Serial.print("Button is pressed. Pin is: ");
    Serial.println(pin);
      delay(250);
  }
  // lastButton = pressed;
}

long int modeLastChanged = 0;
int prevClk = HIGH;
void readEncoder() {
  if (digitalRead(ENCODER_SW) == LOW && millis() - modeLastChanged > 300) {
    modeLastChanged = millis();
    // Do mute or 
  }

  int clk = digitalRead(ENCODER_CLK);
  if (clk != prevClk && clk == LOW) {
    int dt = digitalRead(ENCODER_DT);
    int delta = dt == HIGH ? 1 : 2;

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
