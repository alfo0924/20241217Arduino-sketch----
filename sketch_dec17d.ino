void setup() {
  Serial.begin(115200);           // 設定串列通訊鮑率
  pinMode(4, INPUT_PULLUP);       // 設定 Pin 4 為輸入，啟用內建上拉電阻
  pinMode(16, OUTPUT);            // 設定 Pin 16 為輸出
}

void loop() {
  if (Serial.available() > 0) {   // 當串列埠收到資料
    char receivedChar = Serial.read();    // 讀取 ASCII 字元
    byte binaryArray[8];                  // 建立 8 位元陣列儲存二進位值
    
    // 將 ASCII 字元轉換為二進位
    for (int i = 0; i < 8; i++) {
      binaryArray[7 - i] = (receivedChar >> i) & 1;
    }
    
    // 在 Monitor 顯示完整二進位值
    Serial.print("Binary: ");
    for (int i = 0; i < 8; i++) {
      Serial.print(binaryArray[i]);
    }
    Serial.println();  // 換行
    
    // 透過 Serial Plotter 顯示各位元的波形
    for (int i = 0; i < 8; i++) {
      Serial.println(binaryArray[i]);  // 輸出單一位元的值
      delay(500);                      // 延遲 0.5 秒
    }
  }
}
