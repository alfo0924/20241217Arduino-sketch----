// 宣告計時器變數
hw_timer_t *timer = NULL;
// 宣告一個字串用來存儲二進制數值
String binaryString = "";

// 中斷函數，當計時器觸發時會執行
void ARDUINO_ISR_ATTR interrupt_func() {
    if(binaryString.length() > 0) {
        // 讀取二進制字串的第一個字符
        char bit = binaryString.charAt(0);
        // 根據二進制位設置 GPIO 16 的狀態
        digitalWrite(16, bit == '1' ? HIGH : LOW);
        // 移除已處理的位
        binaryString = binaryString.substring(1);
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(4, INPUT_PULLUP);
    pinMode(16, OUTPUT);
    
    timer = timerBegin(1000000);
    timerAttachInterrupt(timer, &interrupt_func);
    timerAlarm(timer, 500000, true, 0);
}

void loop() {
    if(Serial.available() > 0) {
        // 讀取輸入的字符
        char input = Serial.read();
        // 將 ASCII 字符轉換為二進制字串
        binaryString = "";
        for(int i = 7; i >= 0; i--) {
            binaryString += ((input >> i) & 1) ? '1' : '0';
        }
        Serial.print("Input ASCII: ");
        Serial.println(input);
        Serial.print("Binary: ");
        Serial.println(binaryString);
    }
    
    Serial.println(digitalRead(4));
    delay(30000);
}
