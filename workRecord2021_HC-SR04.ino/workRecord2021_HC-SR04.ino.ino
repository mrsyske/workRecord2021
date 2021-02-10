#define Trig 8
#define Echo A0

int duration;
float distance;

void setup(){
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}

void loop(){
  digitalWrite(Trig, LOW); //①TrigピンをLOWにする
  delayMicroseconds(1); //②1usウェイト
  digitalWrite(Trig, HIGH); //③TrigピンをHIGHにする
  delayMicroseconds(10); //④10usウェイト
  digitalWrite(Trig, LOW);//⑤Trigピンを再びLOWにする。Trigピンをオフ→オン→オフした。
  duration = pulseIn(Echo, HIGH);//⑥EchoピンがHIGHの時間を計測する
  if(duration > 0){
    //HC-SR04の仕様に従って距離を計算
    distance = duration/2;
    distance = distance*340*100/1000000;
    Serial.println(distance);//シリアルモニタに距離を表示する
  }
  delay(500); //0.5秒おきに距離を演算する。
}
//今日はここまで。ありがとうございました。
