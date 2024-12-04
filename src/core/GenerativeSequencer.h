// src/core/GenerativeSequencer.h
class GenerativeSequencer {
private:
    static std::array<Note, MAX_SEQUENCE_LENGTH> sequence;
    static std::array<uint8_t, MAX_SEQUENCE_LENGTH> pattern;
    std::array<float, AUDIO_BUFFER_SIZE> audioBuffer;
    uint8_t sequenceLength;
    uint8_t currentStep;
    float phase;
    float sampleRate;
    EvolutionParameters evoParams;
    EvolutionVisualizer& visualizer;
    
    // Error handling
    enum class SequencerError { NONE, BUFFER_FULL, INVALID_INDEX };
    SequencerError lastError = SequencerError::NONE;
