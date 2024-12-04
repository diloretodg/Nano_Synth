#include "Constants.h"

hw_timer_t* timer = nullptr;

void setupDAC() {
    esp_err_t err = dac_output_enable(DAC_CHANNEL);
    if (err != ESP_OK) {
        Serial.println("DAC output enable failed");
        return;
    }
    dac_output_voltage(DAC_CHANNEL, 0);
}

void setupTimer() {
    timer = timerBegin(0, TIMER_DIVIDER, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, ALARM_VALUE, true);
    timerAlarmEnable(timer);
}

void IRAM_ATTR onTimer() {
    if (sequencer) {
        float sample = sequencer->generateSample();
        uint8_t dacValue = static_cast<uint8_t>((sample + 1.0f) * 127.5f);
        dac_output_voltage(DAC_CHANNEL, dacValue);
    }
}
