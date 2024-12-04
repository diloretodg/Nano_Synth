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
constexpr uint8_t TIMER_GROUP = 0;
constexpr uint8_t TIMER_NUMBER = 0;
constexpr uint32_t APB_CLK_FREQ = 80000000;
constexpr uint32_t TIMER_DIVIDER = 80;
constexpr uint32_t TIMER_SCALE = APB_CLK_FREQ / TIMER_DIVIDER;
constexpr uint64_t TIMER_INTERVAL = (1000000ULL * TIMER_DIVIDER) / SAMPLE_RATE;

#endif
