// Constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "driver/dac.h"

// Audio Constants
constexpr uint32_t SAMPLE_RATE = 44100;
constexpr uint16_t AUDIO_BUFFER_SIZE = 256;

// Timer Constants
constexpr uint8_t TIMER_GROUP = 0;
constexpr uint8_t TIMER_NUMBER = 0;
constexpr uint32_t TIMER_DIVIDER = 80;  // 80MHz / 80 = 1MHz
constexpr uint32_t TIMER_SCALE = 1000000;  // 1MHz = 1,000,000 microseconds

constexpr float MIN_FREQUENCY = 20.0f;
constexpr float MAX_FREQUENCY = 20000.0f;
constexpr float SEMITONE_RATIO = 1.059463094359f;

// Hardware Constants
constexpr uint8_t ENCODER_PIN_A = 32;
constexpr uint8_t ENCODER_PIN_B = 33;
constexpr uint8_t ENCODER_BUTTON = 34;
// Use the proper DAC channel enum
#define DAC_CHANNEL DAC_CHANNEL_1
// Make sure these match your ESP32 board's DAC channels
#ifndef DAC_CHANNEL_1
#define DAC_CHANNEL_1 DAC_CHANNEL_1_GPIO25_IDX
#endif

// In Definitions.h or Constants.h (wherever your display constants are)
#ifndef SSD1306_SWITCHCAPVCC
#define SSD1306_SWITCHCAPVCC 0x2
#endif

#ifndef SSD1306_WHITE
#define SSD1306_WHITE 1
#endif

// Audio settings
constexpr float DEFAULT_VOLUME = 0.75f;
constexpr uint8_t DAC_CHANNEL_1 = 0;

// Timer settings
constexpr uint8_t TIMER_GROUP = 0;
constexpr uint8_t TIMER_NUMBER = 0;
constexpr uint32_t APB_CLK_FREQ = 80000000;

// Timing Constants
constexpr uint16_t DISPLAY_UPDATE_INTERVAL = 50;  // milliseconds
constexpr uint8_t DEBOUNCE_DELAY = 50;           // milliseconds

// MIDI settings
constexpr uint8_t MIDI_CHANNEL = 1;
constexpr uint8_t MIDI_CC_VOLUME = 7;
constexpr uint8_t MIDI_CC_MODULATION = 1;

// Display Constants
constexpr uint8_t SCREEN_WIDTH = 128;
constexpr uint8_t SCREEN_HEIGHT = 64;
constexpr int8_t OLED_RESET = -1;
constexpr uint8_t SCREEN_ADDRESS = 0x3C;

// Sequencer Constants
static constexpr uint8_t MAX_STEPS = 16;
static constexpr uint8_t DEFAULT_SEQUENCE_LENGTH = 8;
static constexpr uint8_t DEFAULT_STEP_LENGTH = 4;
static constexpr uint8_t DEFAULT_BPM = 120;
static constexpr uint8_t DEFAULT_VELOCITY = 100;

// Evolution Constants
static constexpr float DEFAULT_MUTATION_RATE = 0.1f;
static constexpr float DEFAULT_CROSSOVER_RATE = 0.05f;
static constexpr float DEFAULT_RHYTHM_WEIGHT = 0.5f;
static constexpr float DEFAULT_HARMONIC_WEIGHT = 0.5f;

// Wireless settings
constexpr uint16_t WEB_SERVER_PORT = 80;
constexpr const char* DEFAULT_SSID = "NanoSynth";
constexpr const char* DEFAULT_PASSWORD = "password123";

#endif // CONSTANTS_H
