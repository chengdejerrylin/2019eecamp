int led[] = {9,10,11,12};//LED 連接至數位接腳9~12。
int i;//LED 索引值。
int j=0;//LED 索引值。
void setup() {    
  for(i=0;i<4;i++)//四個LED。
  {  
    pinMode(led[i], OUTPUT);//設定數位接腳9~12為輸出模式。
  }    
}

void loop() {
  for(i=0;i<4;i++)//四個LED。
  {
    digitalWrite(led[i],LOW);//關閉所有LED。
  }  
  digitalWrite(led[j], HIGH);//點亮第j個LED。
  delay(1000);//延遲1秒。
  j++;//右移。
  if(j==4)//已右移至最右方?
    j=0;//重新點亮最左方LED。
}
