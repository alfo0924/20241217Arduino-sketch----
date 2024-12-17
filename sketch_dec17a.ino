// 宣告計時器變數
hw_timer_t *timer = NULL;

// 中斷函數，當計時器觸發時會執行
// 功能：切換 GPIO 16 的電位狀態（高低電位互換）
void ARDUINO_ISR_ATTR interrupt_func() {
    digitalWrite(16, !digitalRead(16));
}

void setup() {
    // 初始化序列埠，設定鮑率為 115200
    Serial.begin(115200);
    
    // 設定 GPIO 4 為輸入腳位，並啟用內建上拉電阻
    pinMode(4, INPUT_PULLUP);
    
    // 設定 GPIO 16 為輸出腳位
    pinMode(16, OUTPUT);
    
    // 初始化計時器，設定計時器時脈為 1MHz (1000000Hz)
    timer = timerBegin(1000000);
    
    // 將中斷函數綁定到計時器
    timerAttachInterrupt(timer, &interrupt_func);
    
    // 設定計時器觸發條件：
    // - 每 500000 微秒(0.5秒)觸發一次
    // - true 表示重複觸發
    // - 0 表示計數器從 0 開始
    timerAlarm(timer, 500000, true, 0);
}

// 主程式迴圈
void loop() {
    // 讀取並印出 GPIO 4 的電位狀態
    Serial.println(digitalRead(4));
    
    // 延遲 30 毫秒
    delay(30);
}
