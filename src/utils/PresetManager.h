// PresetManager.h
#ifndef PRESET_MANAGER_H
#define PRESET_MANAGER_H

#include <EEPROM.h>
#include "Constants.h"
#include "Definitions.h"

class PresetManager {
private:
    static constexpr int EEPROM_START_ADDRESS = 0;
    static constexpr int PRESET_SIZE = sizeof(Preset);
    static constexpr int EEPROM_SIZE = MAX_PRESETS * PRESET_SIZE;

public:
    PresetManager() {
        EEPROM.begin(EEPROM_SIZE);
    }

    bool savePreset(uint8_t slot, const Preset& preset) {
        if (slot >= MAX_PRESETS) return false;

        int address = EEPROM_START_ADDRESS + (slot * PRESET_SIZE);
        uint8_t* data = (uint8_t*)&preset;

        for (size_t i = 0; i < PRESET_SIZE; i++) {
            EEPROM.write(address + i, data[i]);
        }

        return EEPROM.commit();
    }

    bool loadPreset(uint8_t slot, Preset& preset) {
        if (slot >= MAX_PRESETS) return false;

        int address = EEPROM_START_ADDRESS + (slot * PRESET_SIZE);
        uint8_t* data = (uint8_t*)&preset;

        for (size_t i = 0; i < PRESET_SIZE; i++) {
            data[i] = EEPROM.read(address + i);
        }

        return true;
    }

    void initializeEEPROM() {
        // Initialize with default values if needed
        Preset defaultPreset;
        defaultPreset.masterVolume = 0.75f;
        defaultPreset.tempo = DEFAULT_BPM;
        defaultPreset.stepLength = DEFAULT_STEP_LENGTH;

        for (int i = 0; i < MAX_STEPS; i++) {
            defaultPreset.steps[i].frequency = 440.0f;  // A4 note
            defaultPreset.steps[i].amplitude = 0.0f;
            defaultPreset.steps[i].waveform = WaveformType::SINE;
            defaultPreset.steps[i].duration = 125;
            defaultPreset.steps[i].gate = 0;
        }

        // Save default preset to first slot
        savePreset(0, defaultPreset);
    }

    void eraseAllPresets() {
        for (int i = 0; i < EEPROM_SIZE; i++) {
            EEPROM.write(i, 0);
        }
        EEPROM.commit();
    }

    bool isPresetValid(uint8_t slot) {
        if (slot >= MAX_PRESETS) return false;

        // Add validation logic here if needed
        // For example, check for a magic number or checksum
        return true;
    }
};

#endif // PRESET_MANAGER_H