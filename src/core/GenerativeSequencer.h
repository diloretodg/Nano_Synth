// GenerativeSequencer.h
#ifndef GENERATIVE_SEQUENCER_H
#define GENERATIVE_SEQUENCER_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include "Constants.h"
#include "Definitions.h"
#include "EvolutionVisualizer.h"

class GenerativeSequencer {
private:
    SequenceStep steps[MAX_STEPS];
    uint8_t sequenceLength;
    uint8_t currentStep;
    bool isPlaying;
    float phase;
    float sampleRate;
    EvolutionParameters evoParams;
    EvolutionVisualizer visualizer;

    // Parameter selection tracking
    uint8_t selectedParameter = 0;
    uint8_t selectedEvolutionParameter = 0;

public:
    explicit GenerativeSequencer(Adafruit_SSD1306& display) 
        : sequenceLength(DEFAULT_SEQUENCE_LENGTH)
        , currentStep(0)
        , isPlaying(false)
        , phase(0.0f)
        , sampleRate(SAMPLE_RATE)
        , evoParams(DEFAULT_MUTATION_RATE, 
                   DEFAULT_CROSSOVER_RATE, 
                   DEFAULT_RHYTHM_WEIGHT, 
                   DEFAULT_HARMONIC_WEIGHT)
        , visualizer(display) 
    {
        initializeSequence();
    }

    void start() {
        isPlaying = true;
    }

    void stop() {
        isPlaying = false;
    }

    void toggle() {
        isPlaying = !isPlaying;
    }

    float generateSample() {
        if (!isPlaying) return 0.0f;

        float sample = 0.0f;
        const SequenceStep& step = steps[currentStep];

        // Generate waveform
        switch (step.waveform) {
            case WaveformType::SINE:
                sample = sin(2.0f * PI * phase);
                break;
            case WaveformType::SQUARE:
                sample = phase < 0.5f ? 1.0f : -1.0f;
                break;
            case WaveformType::TRIANGLE:
                sample = 4.0f * abs(phase - 0.5f) - 1.0f;
                break;
            case WaveformType::SAW:
                sample = 2.0f * phase - 1.0f;
                break;
        }

        // Apply amplitude
        sample *= step.amplitude;

        // Update phase
        phase += step.frequency / sampleRate;
        if (phase >= 1.0f) {
            phase -= 1.0f;
            // Move to next step
            currentStep = (currentStep + 1) % sequenceLength;
        }

        return sample;
    }

    void update() {
        // Update visualization
        visualizer.update(currentStep, steps, sequenceLength, evoParams);
    }

    void adjustCurrentStep(long difference) {
        currentStep = (currentStep + difference + sequenceLength) % sequenceLength;
    }

    // In GenerativeSequencer.h, replace the adjustParameter method with:
void adjustParameter(long difference) {
    SequenceStep& step = steps[currentStep];

    switch (selectedParameter) {
        case 0: { // Frequency
            step.frequency = constrain(
                step.frequency * (difference > 0 ? SEMITONE_RATIO : 1.0f/SEMITONE_RATIO),
                MIN_FREQUENCY,
                MAX_FREQUENCY
            );
            break;
        }
        case 1: { // Amplitude
            step.amplitude = constrain(
                step.amplitude + (difference * 0.01f),
                0.0f,
                1.0f
            );
            break;
        }
        case 2: { // Waveform
            int waveform = static_cast<int>(step.waveform);
            waveform = (waveform + difference + 4) % 4; // 4 waveform types
            step.waveform = static_cast<WaveformType>(waveform);
            break;
        }
        case 3: { // Duration
            step.duration = constrain(
                step.duration + difference,
                1,
                16
            );
            break;
        }
        case 4: { // Velocity
            step.velocity = constrain(
                step.velocity + (difference * 5),
                0,
                127
            );
            break;
        }
    }
}
    void adjustEvolutionParameter(long difference) {
        switch (selectedEvolutionParameter) {
            case 0: // Mutation Rate
                evoParams.mutationRate = constrain(
                    evoParams.mutationRate + (difference * 0.01f),
                    0.0f,
                    1.0f
                );
                break;
            case 1: // Crossover Rate
                evoParams.crossoverRate = constrain(
                    evoParams.crossoverRate + (difference * 0.01f),
                    0.0f,
                    1.0f
                );
                break;
            case 2: // Rhythm Weight
                evoParams.rhythmWeight = constrain(
                    evoParams.rhythmWeight + (difference * 0.01f),
                    0.0f,
                    1.0f
                );
                break;
            case 3: // Harmonic Weight
                evoParams.harmonicWeight = constrain(
                    evoParams.harmonicWeight + (difference * 0.01f),
                    0.0f,
                    1.0f
                );
                break;
        }
    }

    void nextParameter() {
        selectedParameter = (selectedParameter + 1) % 5; // 5 parameters total
    }

    void nextEvolutionParameter() {
        selectedEvolutionParameter = (selectedEvolutionParameter + 1) % 4; // 4 evolution parameters
    }

    // Getter methods for UI
    const SequenceStep& getCurrentStep() const {
        return steps[currentStep];
    }

    uint8_t getCurrentStepIndex() const {
        return currentStep;
    }

    uint8_t getSelectedParameter() const {
        return selectedParameter;
    }

    uint8_t getSelectedEvolutionParameter() const {
        return selectedEvolutionParameter;
    }

    const EvolutionParameters& getEvolutionParameters() const {
        return evoParams;
    }

private:
    void initializeSequence() {
        for (uint8_t i = 0; i < MAX_STEPS; i++) {
            float baseFreq = 440.0f;
            float randomSemitones = random(-12, 13);
            float frequency = baseFreq * pow(SEMITONE_RATIO, randomSemitones);
            frequency = constrain(frequency, MIN_FREQUENCY, MAX_FREQUENCY);

            steps[i] = SequenceStep(
                frequency,                              // frequency
                DEFAULT_VOLUME,                         // amplitude
                static_cast<WaveformType>(random(4)),   // waveform
                DEFAULT_STEP_LENGTH,                    // duration
                DEFAULT_VELOCITY                        // velocity
            );
        }
    }

    void evolveSequence() {
        // Implement evolution logic here
        // This could include mutation and crossover operations
        for (uint8_t i = 0; i < sequenceLength; i++) {
            if (random(100) < evoParams.mutationRate * 100) {
                // Perform mutation
                float randomChange = (random(100) / 100.0f - 0.5f) * 2.0f;
                steps[i].frequency *= (1.0f + randomChange * evoParams.harmonicWeight);
                steps[i].frequency = constrain(steps[i].frequency, MIN_FREQUENCY, MAX_FREQUENCY);

                if (random(100) < 50) {
                    steps[i].duration = constrain(
                        steps[i].duration + (random(3) - 1) * evoParams.rhythmWeight,
                        1,
                        16
                    );
                }
            }
        }
    }
};

#endif // GENERATIVE_SEQUENCER_H