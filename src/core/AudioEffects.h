// src/core/AudioEffects.h
#include "../../include/Constants.h"

class Effects {
private:
    static constexpr size_t MAX_EFFECTS = 8;
    static std::array<Effect, MAX_EFFECTS> effectBuffer;
    static constexpr size_t MAX_DELAY_SAMPLES = 4096;
    std::array<float, MAX_DELAY_SAMPLES> delayBuffer;
    size_t delayIndex = 0;
    float feedback = 0.3f;
