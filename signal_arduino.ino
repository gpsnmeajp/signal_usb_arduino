const int RED = 8;
const int YELLOW = 7;
const int GREEN = 6;

const int LIGHT_ON = LOW;
const int LIGHT_OFF = HIGH;

unsigned long t = 0;

void setup() {
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  digitalWrite(RED, LIGHT_ON);
  digitalWrite(YELLOW, LIGHT_ON);
  digitalWrite(GREEN, LIGHT_ON);
  delay(500);
}

void light(int n) {
  digitalWrite(RED, !(n & 1));
  digitalWrite(YELLOW, !(n & 2));
  digitalWrite(GREEN, !(n & 4));
}

void loop() {
  int n = Serial.read();
  //受信データの下位3bit
  if (n > 0) {
    light(n);
    //無信号時間を更新
    t = millis();
  }else if (n == 0) {
    //無信号時間を更新
    t = millis();
  }
  //30秒間無信号だったらデモモードに入る
  if (millis() - t > 30 * 1000) {
    light(millis() >> 14);
  }
}
