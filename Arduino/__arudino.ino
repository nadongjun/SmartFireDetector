#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
//아두이노 핀설정

int piezo = 0;//스피커
int temp = 1;//온도


void setup() {

  pinMode(piezo, OUTPUT);
  pinMode(light, OUTPUT);
  Serial.begin(115200);
  bluetooth.begin(115200);
}
void loop() {
  //아날로그 신호 저장
  int temp = analogRead(A0); //온도 
  int gas = analogRead(A1);  //가스
  if(temp > || gas >) { //온도와 가스가 일정 값보다 클경우
    //스피커와 led 활성화
    digitalWrite(piezo,HIGH);
    digitalWrite(light,HIGH);
  }
  else {
    //낮을 경우 비활성화
    digitalWrite(piezo,LOW);
    digitalWrite(light,LOW);
  }
  Serial.print("<");
  Serial.print(temp);//시리얼 모니터로 온도, 가스 전송
  Serial.print(">");
  Serial.print("(");
  Serial.print(gas);
  Serial.print(")");
  bluetooth.print("<");
  bluetooth.print(temp); // 블루투스로 온도, 가스 전송
  bluetooth.print(">");
  bluetooth.print("(");
  bluetooth.print(gas);
  bluetooth.print(")");
}



