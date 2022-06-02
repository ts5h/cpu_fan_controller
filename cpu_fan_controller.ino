// CPU Fan Control from Pro micro
// AMD Wraith Prism

const unsigned int ANALOG_RATE_INPUT = A0;
const unsigned int ANALOG_RATE_OUTPUT = 3;

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
unsigned int averageCycle = 30;

void setup() {
  pinMode(ANALOG_RATE_INPUT, INPUT);
  pinMode(ANALOG_RATE_OUTPUT, OUTPUT);

  pinMode(ANALOG_R_INPUT, INPUT);
  pinMode(ANALOG_G_INPUT, INPUT);
  pinMode(ANALOG_B_INPUT, INPUT);
  pinMode(ANALOG_R_OUTPUT, OUTPUT);
  pinMode(ANALOG_G_OUTPUT, OUTPUT);
  pinMode(ANALOG_B_OUTPUT, OUTPUT);

  // Serial.begin(9600);
}

void loop() {
  rate = 0;
  red = 0;
  green = 0;
  blue = 0;

  for (int i = 0; i < averageNum; i++) {
    rate += analogRead(ANALOG_RATE_INPUT);
    red += analogRead(ANALOG_R_INPUT);
    green += analogRead(ANALOG_G_INPUT);
    blue += analogRead(ANALOG_B_INPUT);

    delay(averageCycle);
  }

  rate = rate / averageNum;
  red = red / averageNum;
  green = green / averageNum;
  blue = blue / averageNum;

  analogWrite(ANALOG_RATE_OUTPUT, rate);
  analogWrite(ANALOG_R_OUTPUT, red);
  analogWrite(ANALOG_G_OUTPUT, green);
  analogWrite(ANALOG_B_OUTPUT, blue);

  Serial.println(red);
}
