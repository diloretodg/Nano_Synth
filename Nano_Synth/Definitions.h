// Definitions.h
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "Constants.h"

// Forward declarations
class GenerativeSequencer;

// Enums
enum class WaveformType {
    SINE,
    SQUARE,
    TRIANGLE,
    SAW,
    NOISE,
    NUM_WAVEFORMS
};

enum class EvolutionParameterType {
    MUTATION_RATE,
    CROSSOVER_RATE,
    RHYTHM_WEIGHT,
    HARMONIC_WEIGHT
};
// In Definitions.h
enum class InterfaceMode {
    EDIT_SEQUENCE,
    EDIT_PARAMETER,
    EDIT_EVOLUTION
};

// Structures
struct SequenceStep {
    float frequency;
    float amplitude;
    WaveformType waveform;
    uint8_t duration;
    uint8_t velocity;

    SequenceStep(float f = 440.0f, 
                float a = 0.75f, 
                WaveformType w = WaveformType::SINE,
                uint8_t d = 4, 
                uint8_t v = 100)
        : frequency(f)
        , amplitude(a)
        , waveform(w)
        , duration(d)
        , velocity(v)
    {}
};


// In Definitions.h, update the EvolutionParameters struct:
struct EvolutionParameters {
    float mutationRate;
    float crossoverRate;
    float rhythmWeight;
    float harmonicWeight;

    EvolutionParameters(float mut = 0.0f, float cross = 0.0f, float rhythm = 0.5f, float harmonic = 0.5f)
        : mutationRate(mut)
        , crossoverRate(cross)
        , rhythmWeight(rhythm)
        , harmonicWeight(harmonic)
    {}
};

struct EvolutionEvent {
    uint8_t stepIndex;
    uint8_t parameterIndex;
    float value;
    uint32_t timestamp;

    EvolutionEvent(uint8_t step = 0, uint8_t param = 0, float val = 0.0f)
        : stepIndex(step), parameterIndex(param), value(val), timestamp(millis()) {}
};

#endif // DEFINITIONS_H