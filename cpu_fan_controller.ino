// CPU Fan Control
// from Pro micro to AMD Wraith Prism

const unsigned int ANALOG_RATE_INPUT = A0;
const unsigned int ANALOG_RATE_OUTPUT = 10;

const unsigned int ANALOG_R_INPUT = A1;
const unsigned int ANALOG_G_INPUT = A2;
const unsigned int ANALOG_B_INPUT = A3;
const unsigned int ANALOG_R_OUTPUT = 5;
const unsigned int ANALOG_G_OUTPUT = 6;
const unsigned int ANALOG_B_OUTPUT = 9;

unsigned int rate = 0;
unsigned int red = 0;
unsigned int green = 0;
unsigned int blue = 0;

unsigned int averageNum = 10;
unsigned int averageCycle = 10;

void setup() {
  pinMode(ANALOG_RATE_INPUT, INPUT);
  pinMode(ANALOG_RATE_OUTPUT, OUTPUT);

  pinMode(ANALOG_R_INPUT, INPUT);
  pinMode(ANALOG_G_INPUT, INPUT);
  pinMode(ANALOG_B_INPUT, INPUT);
  pinMode(ANALOG_R_OUTPUT, OUTPUT);
  pinMode(ANALOG_G_OUTPUT, OUTPUT);
  pinMode(ANALOG_B_OUTPUT, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  rate = 0;
  red = 0;
  green = 0;
  blue = 0;

  for (unsigned int i = 0; i < averageNum; i++) {
    rate += analogRead(ANALOG_RATE_INPUT);
    red += analogRead(ANALOG_R_INPUT);
    green += analogRead(ANALOG_G_INPUT);
    blue += analogRead(ANALOG_B_INPUT);

    delay(averageCycle);
  }

  rate = rate / averageNum / 4;
  red = red / averageNum / 4;
  green = green / averageNum / 4;
  blue = blue / averageNum / 4;

  analogWrite(ANALOG_RATE_OUTPUT, rate);
  analogWrite(ANALOG_R_OUTPUT, red);
  analogWrite(ANALOG_G_OUTPUT, green);
  analogWrite(ANALOG_B_OUTPUT, blue);

  Serial.println(rate);
}
