
// 宣告一個字串用來存儲二進制數值
String binaryString = "";

void setup() {
    Serial.begin(115200);
    pinMode(4, INPUT_PULLUP);
    pinMode(16, OUTPUT);
}

void loop() {
    if(Serial.available() > 0) {
        // 讀取輸入的字符
        char input = Serial.read();
        
        // 將 ASCII 字符轉換為二進制字串
        binaryString = "";
        for(int i = 7; i >= 0; i--) {
            // 計算二進制值並設定 GPIO 16 的狀態
            int bitValue = (input >> i) & 1;
            digitalWrite(16, bitValue);
            binaryString += bitValue ? '1' : '0';
            
            // 顯示當前狀態
            Serial.print("Bit ");
            Serial.print(i);
            Serial.print(": ");
            Serial.println(bitValue);
            
            // 延遲 300 毫秒，讓 LED 變化可見
            delay(300);
        }
        
        // 顯示完整資訊
        Serial.print("Input ASCII: ");
        Serial.println(input);
        Serial.print("Binary: ");
        Serial.println(binaryString);
    }
}
