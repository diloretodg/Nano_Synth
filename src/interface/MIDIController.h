// MIDIController.h
#ifndef MIDI_CONTROLLER_H
#define MIDI_CONTROLLER_H

#include <MIDI.h>
#include "Constants.h"
#include "GenerativeSequencer.h"

class MIDIController {
private:
    MIDI_CREATE_DEFAULT_INSTANCE();
    GenerativeSequencer& sequencer;
    uint8_t currentChannel;
    bool isEnabled;

public:
    MIDIController(GenerativeSequencer& seq) 
        : sequencer(seq)
        , currentChannel(MIDI_CHANNEL)
        , isEnabled(false) 
    {}

    void setup() {
        MIDI.begin(MIDI_CHANNEL);
        MIDI.setHandleNoteOn(handleNoteOn);
        MIDI.setHandleNoteOff(handleNoteOff);
        MIDI.setHandleControlChange(handleControlChange);
        isEnabled = true;
    }

    void update() {
        if (!isEnabled) return;
        MIDI.read();
    }

    void sendNote(uint8_t note, uint8_t velocity, uint8_t channel = 0) {
        if (!isEnabled) return;
        channel = channel == 0 ? currentChannel : channel;
        MIDI.sendNoteOn(note, velocity, channel);
    }

    void stopNote(uint8_t note, uint8_t channel = 0) {
        if (!isEnabled) return;
        channel = channel == 0 ? currentChannel : channel;
        MIDI.sendNoteOff(note, 0, channel);
    }

private:
    static void handleNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
        float frequency = 440.0f * pow(2.0f, (note - 69) / 12.0f);
        float amplitude = velocity / 127.0f;
    }

    static void handleNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
    }

    static void handleControlChange(uint8_t channel, uint8_t number, uint8_t value) {
        switch (number) {
            case MIDI_CC_VOLUME:
                float volume = value / 127.0f;
                break;

            case MIDI_CC_MODULATION:
                float modulation = value / 127.0f;
                break;
        }
    }
};

#endif // MIDI_CONTROLLER_H