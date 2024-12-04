#include "include/Constants.h"
#include "src/core/GenerativeSequencer.h"

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        Serial.println("Timer setup failed");
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

void IRAM_ATTR onTimer() {
    static portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
    portENTER_CRITICAL_ISR(&timerMux);
    if (sequencer) {
        float sample = sequencer->generateSample();
        uint8_t dacValue = static_cast<uint8_t>((sample + 1.0f) * 127.5f);
        dac_output_voltage(DAC_CHANNEL_1, dacValue);
    }
    portEXIT_CRITICAL_ISR(&timerMux);
}

void setup() {
    Serial.begin(115200);
    bool setupSuccess = true;

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed - cannot continue"));
        setupSuccess = false;
    }

    if (!setupDisplay()) {
        Serial.println(F("Display initialization failed - continuing with limited functionality"));
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed - cannot continue"));
        setupSuccess = false;
    }

    static GenerativeSequencer sequencerInstance(display);
    sequencer = &sequencerInstance;

    if (!setupSuccess) {
        Serial.println(F("Critical initialization failed - entering error state"));
        enterErrorState();
    }
}
