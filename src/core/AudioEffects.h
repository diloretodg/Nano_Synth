// AudioEffects.h
#ifndef AUDIO_EFFECTS_H
#define AUDIO_EFFECTS_H

class AntiAliasingFilter {
    float prevSample = 0.0f;
public:
    float process(float input);
};

class Effects {
    float delay[4096] = {0};
    size_t delayIndex = 0;
    float feedback = 0.3f;
public:
    float processDelay(float input);
    void setFeedback(float value);
};

#endif
