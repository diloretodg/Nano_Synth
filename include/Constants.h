#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "driver/dac.h"

// Audio Constants
constexpr uint32_t SAMPLE_RATE = 44100;
constexpr uint16_t AUDIO_BUFFER_SIZE = 256;
constexpr float MIN_FREQUENCY = 20.0f;
constexpr float MAX_FREQUENCY = 20000.0f;
constexpr float SEMITONE_RATIO = 1.059463094359f;

// DAC Configuration
#define DAC_OUTPUT_PIN GPIO_NUM_25
#define DAC_CHANNEL DAC_CHANNEL_1

// Timer Configuration
constexpr uint32_t TIMER_DIVIDER = 2;
constexpr uint32_t TIMER_SCALE = 40000000;
constexpr uint32_t ALARM_VALUE = TIMER_SCALE / SAMPLE_RATE;

#endif
