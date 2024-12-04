#ifndef CONSTANTS_H
#define CONSTANTS_H

// Timer Configuration
constexpr uint8_t TIMER_GROUP = 0;
constexpr uint8_t TIMER_NUMBER = 0;
constexpr uint32_t APB_CLK_FREQ = 80000000;
constexpr uint32_t TIMER_DIVIDER = 80;
constexpr uint32_t TIMER_SCALE = APB_CLK_FREQ / TIMER_DIVIDER;
constexpr uint64_t TIMER_INTERVAL = (1000000ULL * TIMER_DIVIDER) / SAMPLE_RATE;

#endif
