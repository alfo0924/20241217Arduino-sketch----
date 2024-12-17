# sketch_dec17a.ino

## 程式運作原理

**硬體計時器設置**
- 程式使用 ESP32 的硬體計時器（Hardware Timer）來產生精確的時間中斷
- 透過 `hw_timer_t` 宣告一個計時器物件，初始值設為 NULL
- 計時器設定為 1MHz 頻率，也就是每一個計時單位為 1 微秒

**中斷處理機制**
- `interrupt_func()` 是一個中斷服務程序（ISR, Interrupt Service Routine）
- 使用 `ARDUINO_ISR_ATTR` 確保中斷函數被正確地放置在 RAM 中
- 當計時器觸發時，中斷函數會執行並切換 GPIO 16 的狀態（高電位變低電位，低電位變高電位）

**初始化流程（setup）**
1. 設定序列通訊速率為 115200 bps，用於輸出除錯訊息
2. GPIO 4 設為輸入模式並啟用內建上拉電阻，確保腳位在懸空時維持高電位
3. GPIO 16 設為輸出模式，用於控制 LED 或其他輸出裝置
4. 計時器初始化過程：
   - `timerBegin(1000000)` 設定基本頻率
   - `timerAttachInterrupt()` 將中斷函數與計時器連結
   - `timerAlarm()` 設定每 500000 微秒（0.5秒）觸發一次中斷

**主程式循環（loop）**
- 持續讀取 GPIO 4 的狀態並通過序列埠輸出
- 每次讀取後暫停 30 毫秒，避免過於頻繁的讀取造成系統負擔

**程式執行流程**
1. 系統啟動時執行初始化設定
2. 計時器開始運作，每 0.5 秒觸發一次中斷
3. 中斷觸發時自動執行 `interrupt_func()`，切換 GPIO 16 的狀態
4. 同時主程式持續監控 GPIO 4 的輸入狀態

# sketch_dec17b.ino





















# sketch_dec17c.ino


































