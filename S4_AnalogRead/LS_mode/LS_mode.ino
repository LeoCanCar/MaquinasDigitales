#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP 60


void setup() {
  Serial.begin(115200);

  // Configuración del timer para despertar al uC.
  esp_sleep_enable_timer_wakeup(uS_TO_S_FACTOR*TIME_TO_SLEEP);
  Serial.println("ESP32 configurado para despertar cada"+ String(TIME_TO_SLEEP)+"s");

}

void loop() {
  esp_light_sleep_start();

  print_wakeup_reason();
}

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason){
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Despierta debido a señal externa desde RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Despierta debido a señal externa desde RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Despierta debido a timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD: Serial.println("Despierta debido a touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Despierta debido a programa del coprocesador ULP"); break;
    default: Serial.printf("Razón para despertar: %d\n", wakeup_reason);
  }
  delay(1000);
}
