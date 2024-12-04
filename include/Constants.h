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
#define TIMER_PRESCALER 8
#define TIMER_COMPARE_VALUE 249 // For 16MHz clock, 8 prescaler, 8kHz sampling
#define TIMER_INTERRUPT_FREQ 8000

// Memory Constants
#define MAX_SEQUENCE_LENGTH 64
#define MAX_PRESETS 16
#define EEPROM_WEAR_LEVEL_BLOCKS 4

#endif
