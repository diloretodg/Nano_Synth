// GenerativeSequencer.h
#ifndef GENERATIVE_SEQUENCER_H
#define GENERATIVE_SEQUENCER_H

#include "Definitions.h"
#include "EvolutionVisualizer.h"

class GenerativeSequencer {

private:
    struct Preset {
        SequenceStep sequence[MAX_STEPS];
        int currentLength;
        EvolutionParameters evoParams;
        int selectedScale;
    };

    SequenceStep sequence[MAX_STEPS];
    int currentLength;
    int currentStep;
    unsigned long lastStepTime;
    int selectedScale;

    EvolutionParameters evoParams;
    EvolutionVisualizer visualizer;

public:
 EvolutionVisualizer& getVisualizer() { return visualizer; }
    bool isPlaying;
    bool isEvolving;

    GenerativeSequencer() : 
        currentLength(16),
        currentStep(0),
        lastStepTime(0),
        selectedScale(0),
        isPlaying(false),
        isEvolving(false)
    {
        // Initialize evolution parameters
        evoParams = {
            0.5f,  // rhythmicComplexity
            0.5f,  // harmonicComplexity
            0.5f,  // textureComplexity
            0.3f,  // densityModulation
            0.2f,  // pitchDrift
            0.5f,  // scaleWeighting
            0.3f,  // mutationRate
            0.5f,  // patternLength
            0.1f,  // microtonalDrift
            0.2f   // rhythmicSubdivision
        };

        initializeSequence();
    }

    void initializeSequence() {
        for(int i = 0; i < MAX_STEPS; i++) {
            sequence[i].frequency = 440.0f; // A4 as default
            sequence[i].amplitude = 0.5f;
            sequence[i].waveform = SINE;
            sequence[i].duration = 125; // Default 16th notes at 120 BPM
            sequence[i].probability = 100;
        }
    }

    void update(unsigned long currentTime) {
        if(!isPlaying) return;

        if(currentTime - lastStepTime >= sequence[currentStep].duration) {
            nextStep();
            lastStepTime = currentTime;
        }

        if(isEvolving && random(1.0f) < evoParams.mutationRate) {
            evolveStep(currentStep);
        }

        visualizer.updateHistory(*this);
    }

    void nextStep() {
        currentStep = (currentStep + 1) % currentLength;

        // Apply probability
        if(random(100) >= sequence[currentStep].probability) {
            sequence[currentStep].amplitude = 0;
        } else {
            sequence[currentStep].amplitude = 0.5f;
        }
    }

    void evolveStep(int stepIndex) {
        SequenceStep& step = sequence[stepIndex];

        // Evolve timing
        if(random(1.0f) < evoParams.rhythmicComplexity) {
            float baseTime = 125.0f;
            float subdivision = pow(2, floor(random(3)));
            step.duration = baseTime * subdivision * 
                           (1.0f + (random(-25, 25) / 100.0f * evoParams.rhythmicSubdivision));
            visualizer.addEvent(0, stepIndex, step.duration);
        }

        // Evolve pitch
        if(random(1.0f) < evoParams.harmonicComplexity) {
            step.frequency = calculateFrequency(stepIndex);
            visualizer.addEvent(1, stepIndex, step.frequency);
        }

        // Evolve texture
        if(random(1.0f) < evoParams.textureComplexity) {
            step.waveform = static_cast<WaveformType>(random(NUM_WAVEFORMS));
            step.amplitude = 0.5f + (random(-25, 25) / 100.0f);
            visualizer.addEvent(2, stepIndex, step.amplitude);
        }

        // Pattern length changes
        if(random(1.0f) < evoParams.patternLength * 0.1f) {
            int lengthChange = random(2) * 2 - 1;
            currentLength = constrain(currentLength + lengthChange * 4, 4, MAX_STEPS);
            visualizer.addEvent(3, stepIndex, currentLength);
        }

        // Evolve probability
        if(random(1.0f) < evoParams.densityModulation) {
            step.probability = constrain(
                step.probability + random(-20, 21),
                0,
                100
            );
        }
    }

    float calculateFrequency(int stepIndex) {
        // Base frequency selection
        float baseFreq = 440.0f; // A4
        int octave = random(-1, 2); // -1 to +1 octaves

        // Apply pitch drift
        float drift = 1.0f + ((random(-100, 101) / 1000.0f) * evoParams.pitchDrift);

        // Apply microtonal drift
        if(random(1.0f) < evoParams.microtonalDrift) {
            float microtonal = 1.0f + ((random(-100, 101) / 2000.0f));
            drift *= microtonal;
        }

        return baseFreq * pow(2, octave) * drift;
    }

    // Getters and setters
    int getCurrentLength() const { return currentLength; }
    int getCurrentStepIndex() const { return currentStep; }
    const SequenceStep& getStep(int index) const { return sequence[index]; }
    SequenceStep& getCurrentStep() { return sequence[currentStep]; }
    EvolutionVisualizer& getVisualizer() { return visualizer; }

    void setEvolutionParameter(int param, float value) {
        value = constrain(value, 0.0f, 1.0f);
        switch(param) {
            case EVO_RHYTHM: evoParams.rhythmicComplexity = value; break;
            case EVO_HARMONIC: evoParams.harmonicComplexity = value; break;
            case EVO_TEXTURE: evoParams.textureComplexity = value; break;
            case EVO_DENSITY: evoParams.densityModulation = value; break;
            case EVO_PITCH_DRIFT: evoParams.pitchDrift = value; break;
            case EVO_SCALE_WEIGHT: evoParams.scaleWeighting = value; break;
            case EVO_MUTATION: evoParams.mutationRate = value; break;
            case EVO_PATTERN_LEN: evoParams.patternLength = value; break;
            case EVO_MICROTONAL: evoParams.microtonalDrift = value; break;
            case EVO_SUBDIVISION: evoParams.rhythmicSubdivision = value; break;
        }
    }

    float getEvolutionParameter(int param) const {
        switch(param) {
            case EVO_RHYTHM: return evoParams.rhythmicComplexity;
            case EVO_HARMONIC: return evoParams.harmonicComplexity;
            case EVO_TEXTURE: return evoParams.textureComplexity;
            case EVO_DENSITY: return evoParams.densityModulation;
            case EVO_PITCH_DRIFT: return evoParams.pitchDrift;
            case EVO_SCALE_WEIGHT: return evoParams.scaleWeighting;
            case EVO_MUTATION: return evoParams.mutationRate;
            case EVO_PATTERN_LEN: return evoParams.patternLength;
            case EVO_MICROTONAL: return evoParams.microtonalDrift;
            case EVO_SUBDIVISION: return evoParams.rhythmicSubdivision;
            default: return 0.0f;
        }
    }

    void setScale(int index) {
        selectedScale = constrain(index, 0, sizeof(scales)/sizeof(scales[0]) - 1);
    }

    int getScale() const { return selectedScale; }

    // Preset management
    void savePreset(int slot) {
        if(slot < 0 || slot >= MAX_PRESETS) return;

        Preset preset;
        memcpy(&preset.sequence, sequence, sizeof(sequence));
        preset.currentLength = currentLength;
        preset.evoParams = evoParams;
        preset.selectedScale = selectedScale;

        // Calculate EEPROM address for this preset
        int addr = slot * sizeof(Preset);
        EEPROM.put(addr, preset);
        EEPROM.commit();
    }

    void loadPreset(int slot) {
        if(slot < 0 || slot >= MAX_PRESETS) return;

        Preset preset;
        int addr = slot * sizeof(Preset);
        EEPROM.get(addr, preset);

        memcpy(sequence, preset.sequence, sizeof(sequence));
        currentLength = preset.currentLength;
        evoParams = preset.evoParams;
        selectedScale = preset.selectedScale;
    }

    // Audio generation
    float generateSample() {
        if(!isPlaying || sequence[currentStep].amplitude == 0) {
            return 0.0f;
        }

        float phase = 2.0f * PI * sequence[currentStep].frequency / SAMPLE_RATE;
        float t = millis() / 1000.0f;
        float sample = 0.0f;

        switch(sequence[currentStep].waveform) {
            case SINE:
                sample = sin(phase * t);
                break;
            case SQUARE:
                sample = sin(phase * t) > 0 ? 1.0f : -1.0f;
                break;
            case TRIANGLE:
                sample = asin(sin(phase * t)) * 2.0f / PI;
                break;
            case SAWTOOTH:
                sample = 2.0f * (t * sequence[currentStep].frequency - 
                        floor(0.5f + t * sequence[currentStep].frequency));
                break;
        }

        return sample * sequence[currentStep].amplitude;
    }
};

#endif