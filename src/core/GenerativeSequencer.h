// src/core/GenerativeSequencer.h
class GenerativeSequencer {
private:
    static constexpr size_t MAX_STEPS = 16;
    SequenceStep steps[MAX_STEPS];
    std::array<float, AUDIO_BUFFER_SIZE> audioBuffer;
    uint8_t sequenceLength;
    uint8_t currentStep;
    float phase;
    float sampleRate;
    EvolutionParameters evoParams;
    EvolutionVisualizer& visualizer;
