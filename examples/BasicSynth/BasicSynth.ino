#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}/#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}/#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
} #include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}e#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}x#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}a#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}m#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}p#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}l#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}e#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}s#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}/#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}B#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}a#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}s#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}i#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}c#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}S#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}y#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}n#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}t#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}h#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}/#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}B#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}a#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}s#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}i#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}c#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}S#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}y#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}n#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}t#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}h#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}.#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}i#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}n#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}o#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}
#include "../../src/core/GenerativeSequencer.h"
#include "../../include/Constants.h"

hw_timer_t* timer = nullptr;
GenerativeSequencer* sequencer = nullptr;

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

bool setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        return false;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
    return true;
}

bool setupDAC() {
    dac_output_enable(DAC_CHANNEL_1);
    return true;
}

void setup() {
    Serial.begin(115200);

    if (!setupDAC()) {
        Serial.println(F("DAC initialization failed"));
        return;
    }

    if (!setupTimer()) {
        Serial.println(F("Timer initialization failed"));
        return;
    }

    sequencer = new GenerativeSequencer();
    if (!sequencer) {
        Serial.println(F("Sequencer initialization failed"));
        return;
    }

    Serial.println(F("Initialization complete"));
}

void loop() {
    if (sequencer) {
        sequencer->update();
    }
    delay(1);
}