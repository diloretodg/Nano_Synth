// src/core/AudioEffects.h

class Effects {
private:
    static constexpr size_t MAX_DELAY_SAMPLES = 4096;
    std::array<float, MAX_DELAY_SAMPLES> delayBuffer;
    size_t delayIndex = 0;
    float feedback = 0.3f;
