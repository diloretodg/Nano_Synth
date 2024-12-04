// Nano_Synth.ino
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Encoder.h>
#include "driver/dac.h"
#include "soc/rtc.h"
#include "Constants.h"
#include "Definitions.h"
#include "GenerativeSequencer.h"

// Global objects
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Encoder encoder(ENCODER_PIN_A, ENCODER_PIN_B);
GenerativeSequencer* sequencer = nullptr;
InterfaceMode currentMode = InterfaceMode::EDIT_SEQUENCE;

// Global variables
hw_timer_t* timer = nullptr;
volatile bool audioBufferReady = false;
float audioBuffer[AUDIO_BUFFER_SIZE];
size_t bufferIndex = 0;

void setupDAC() {
    esp_err_t err;
    err = dac_output_enable(DAC_CHANNEL_1);
    if (err != ESP_OK) {
        Serial.println("DAC1 output enable failed");
        return;
    }
    err = dac_output_voltage(DAC_CHANNEL_1, 0);
    if (err != ESP_OK) {
        Serial.println("DAC1 output voltage failed");
        return;
    }
}

void setupTimer() {
    uint32_t apb_freq = APB_CLK_FREQ;
    uint32_t prescaler = 2;
    uint32_t timer_divider = (apb_freq / prescaler) / SAMPLE_RATE;

    timer = timerBegin(TIMER_GROUP, TIMER_NUMBER, prescaler);
    if (timer == nullptr) {
        Serial.println("Timer setup failed");
        return;
    }

    timerAttachInterrupt(timer, &onTimer, true);

    uint64_t alarm_value = (apb_freq / prescaler) / SAMPLE_RATE;
    timerAlarmWrite(timer, alarm_value, true);

    timerAlarmEnable(timer);
    timerStart(timer);
}

#include "include/Constants.h"

hw_timer_t* timer = nullptr;

void setupTimer() {
    timer = timerBegin(TIMER_GROUP, TIMER_DIVIDER, true);
    if (timer == nullptr) {
        Serial.println("Timer setup failed");
        return;
    }
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL, true);
    timerAlarmEnable(timer);
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

    // Timer setup
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS11); // CTC mode, prescaler 8
    OCR1A = TIMER_COMPARE_VALUE;
    TIMSK1 |= (1 << OCIE1A);

    // Error handling
    bool initSuccess = true;
    initSuccess &= initDAC();
    initSuccess &= initDisplay();
    if (!initSuccess) {
        enterErrorState();
    }
}

ISR(TIMER1_COMPA_vect) {
    // Timer interrupt handler
    processAudio();
}

void enterErrorState() {
    // Error handling implementation
    digitalWrite(LED_BUILTIN, HIGH);
    while(1) {
        // Error state loop
    }
}

    // Initialize display
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    display.clearDisplay();
    display.display();

    // Initialize encoder pins
    pinMode(ENCODER_PIN_A, INPUT_PULLUP);
    pinMode(ENCODER_PIN_B, INPUT_PULLUP);
    pinMode(ENCODER_BUTTON, INPUT_PULLUP);

    // Initialize sequencer
    sequencer = new GenerativeSequencer(display);
    sequencer->start();
}

void loop() {
    // Handle encoder
    static long lastEncoderValue = 0;
    long newValue = encoder.read();
    if (newValue != lastEncoderValue) {
        handleEncoderChange(newValue - lastEncoderValue);
        lastEncoderValue = newValue;
    }

    // Handle button
    static bool lastButtonState = HIGH;
    bool buttonState = digitalRead(ENCODER_BUTTON);
    if (buttonState != lastButtonState) {
        if (buttonState == LOW) {
            handleButtonPress();
        }
        lastButtonState = buttonState;
        delay(DEBOUNCE_DELAY);
    }

    // Update display
    static unsigned long lastDisplayUpdate = 0;
    if (millis() - lastDisplayUpdate > DISPLAY_UPDATE_INTERVAL) {
        updateDisplay();
        lastDisplayUpdate = millis();
    }

    // Update sequencer
    if (sequencer) {
        sequencer->update();
    }
}

void handleEncoderChange(long difference) {
    switch (currentMode) {
        case InterfaceMode::EDIT_SEQUENCE:
            sequencer->adjustCurrentStep(difference);
            break;
        case InterfaceMode::EDIT_PARAMETER:
            sequencer->adjustParameter(difference);
            break;
        case InterfaceMode::EDIT_EVOLUTION:
            sequencer->adjustEvolutionParameter(difference);
            break;
    }
}

void handleButtonPress() {
    currentMode = static_cast<InterfaceMode>((static_cast<int>(currentMode) + 1) % 3);
}

void updateDisplay() {
    display.clearDisplay();

    switch (currentMode) {
        case InterfaceMode::EDIT_SEQUENCE:
            drawSequenceEdit();
            break;
        case InterfaceMode::EDIT_PARAMETER:
            drawParameterEdit();
            break;
        case InterfaceMode::EDIT_EVOLUTION:
            drawEvolutionEdit();
            break;
    }

    display.display();
}

void drawSequenceEdit() {
    // Implementation for sequence editing view
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(F("Sequence Edit"));
    // Add more visualization code here
}

void drawParameterEdit() {
    // Implementation for parameter editing view
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(F("Parameter Edit"));
    // Add more visualization code here
}

void drawEvolutionEdit() {
    // Implementation for evolution editing view
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(F("Evolution Edit"));
    // Add more visualization code here
}