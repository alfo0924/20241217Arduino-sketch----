void setup() {
    // 初始化串列通信，波特率為115200
    Serial.begin(115200);
    // 將引腳16設置為輸出模式
    pinMode(16, OUTPUT);
}

void loop() {
    // 如果串列通信中有可讀數據
    if(Serial.available() > 0) {
        // 讀取收到的字元
        char receivedChar = Serial.read();
        // 將收到的字元以數值形式輸出
        Serial.println((int)receivedChar);
    }
}
