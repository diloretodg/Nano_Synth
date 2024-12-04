// Scales.h
#ifndef SCALES_H
#define SCALES_H

#include <Arduino.h>
#include "Constants.h"

enum class ScaleType {
    CHROMATIC,
    MAJOR,
    MINOR,
    PENTATONIC_MAJOR,
    PENTATONIC_MINOR,
    BLUES,
    DORIAN,
    PHRYGIAN,
    LYDIAN,
    MIXOLYDIAN,
    LOCRIAN
};

class MusicalScale {
private:
    static constexpr size_t MAX_INTERVALS = 12;
    float intervals_[MAX_INTERVALS];
    size_t size_;
    float rootFrequency_;
    const char* name_;

public:
    MusicalScale() : size_(0), rootFrequency_(440.0f), name_("") {
        for (size_t i = 0; i < MAX_INTERVALS; i++) {
            intervals_[i] = 1.0f;
        }
    }

    MusicalScale(const float* intervals, size_t size, float rootFreq = 440.0f, const char* name = "")
        : size_(size), rootFrequency_(rootFreq), name_(name)
    {
        for (size_t i = 0; i < size && i < MAX_INTERVALS; i++) {
            intervals_[i] = intervals[i];
        }
    }

    const float* getIntervals() const { return intervals_; }
    const char* getName() const { return name_; }
    size_t getSize() const { return size_; }

    float getNoteFrequency(size_t index) const {
        if (index >= size_) return rootFrequency_;
        return rootFrequency_ * intervals_[index];
    }

    float getRandomNoteFrequency(float randomValue = 0.0f) const {
        size_t index = static_cast<size_t>(randomValue * size_);
        return getNoteFrequency(index);
    }

    float transposeFrequency(float frequency, int semitones) const {
        return frequency * pow(1.059463f, semitones);
    }

    float getOctave(float frequency) const {
        return frequency * 2.0f;
    }

    float getSubOctave(float frequency) const {
        return frequency * 0.5f;
    }

    bool isValid() const {
        return size_ > 0 && size_ <= MAX_INTERVALS;
    }
};

class ScaleManager {
private:
    static constexpr size_t MAX_SCALES = 11;
    MusicalScale scales_[MAX_SCALES];
    size_t numScales_;

    // Private constructor for singleton pattern
    ScaleManager() : numScales_(0) {
        // Define all scale intervals (frequency ratios from root note)
        static const float chromaticIntervals[] = {
            1.0f, 1.059463f, 1.122462f, 1.189207f, 1.259921f, 1.334840f,
            1.414214f, 1.498307f, 1.587401f, 1.681793f, 1.781797f, 1.887749f
        };

        static const float majorIntervals[] = {
            1.0f, 1.122462f, 1.259921f, 1.334840f, 1.498307f, 1.681793f, 1.887749f
        };

        static const float minorIntervals[] = {
            1.0f, 1.122462f, 1.189207f, 1.334840f, 1.498307f, 1.587401f, 1.781797f
        };

        static const float pentatonicMajorIntervals[] = {
            1.0f, 1.122462f, 1.259921f, 1.498307f, 1.681793f
        };

        static const float pentatonicMinorIntervals[] = {
            1.0f, 1.189207f, 1.334840f, 1.498307f, 1.781797f
        };

        static const float bluesIntervals[] = {
            1.0f, 1.189207f, 1.334840f, 1.414214f, 1.498307f, 1.781797f
        };

        static const float dorianIntervals[] = {
            1.0f, 1.122462f, 1.189207f, 1.334840f, 1.498307f, 1.681793f, 1.781797f
        };

        static const float phrygianIntervals[] = {
            1.0f, 1.059463f, 1.189207f, 1.334840f, 1.498307f, 1.587401f, 1.781797f
        };

        static const float lydianIntervals[] = {
            1.0f, 1.122462f, 1.259921f, 1.414214f, 1.498307f, 1.681793f, 1.887749f
        };

        static const float mixolydianIntervals[] = {
            1.0f, 1.122462f, 1.259921f, 1.334840f, 1.498307f, 1.681793f, 1.781797f
        };

        static const float locrianIntervals[] = {
            1.0f, 1.059463f, 1.189207f, 1.334840f, 1.414214f, 1.587401f, 1.781797f
        };

        // Initialize all scales
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(chromaticIntervals, 12, 440.0f, "Chromatic");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(majorIntervals, 7, 440.0f, "Major");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(minorIntervals, 7, 440.0f, "Minor");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(pentatonicMajorIntervals, 5, 440.0f, "Pentatonic Major");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(pentatonicMinorIntervals, 5, 440.0f, "Pentatonic Minor");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(bluesIntervals, 6, 440.0f, "Blues");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(dorianIntervals, 7, 440.0f, "Dorian");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(phrygianIntervals, 7, 440.0f, "Phrygian");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(lydianIntervals, 7, 440.0f, "Lydian");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(mixolydianIntervals, 7, 440.0f, "Mixolydian");
        if (numScales_ < MAX_SCALES) scales_[numScales_++] = MusicalScale(locrianIntervals, 7, 440.0f, "Locrian");
    }

    // Private method to add scales (only used in constructor)
    void addScale(const MusicalScale& scale) {
        if (numScales_ < MAX_SCALES) {
            scales_[numScales_++] = scale;
        }
    }

public:
    // Delete copy constructor and assignment operator
    ScaleManager(const ScaleManager&) = delete;
    ScaleManager& operator=(const ScaleManager&) = delete;

    // Singleton instance getter
    static ScaleManager& getInstance() {
        static ScaleManager instance;
        return instance;
    }

    // Public methods (same as before)
    const MusicalScale& getScale(ScaleType type) const {
        size_t index = static_cast<size_t>(type);
        if (index >= numScales_) {
            return scales_[0]; // Return chromatic scale as default
        }
        return scales_[index];
    }

    float snapToScale(float frequency, const MusicalScale& scale) const {
        if (!scale.isValid()) return frequency;

        float closestFreq = scale.getNoteFrequency(0);
        float minDiff = abs(frequency - closestFreq);

        for (size_t i = 1; i < scale.getSize(); i++) {
            float currentFreq = scale.getNoteFrequency(i);
            float diff = abs(frequency - currentFreq);
            if (diff < minDiff) {
                minDiff = diff;
                closestFreq = currentFreq;
            }
        }
        return closestFreq;
    }

    float getNearestNoteInScale(float frequency, ScaleType scaleType) const {
        const MusicalScale& scale = getScale(scaleType);
        return snapToScale(frequency, scale);
    }

    float getRandomNoteInScale(ScaleType scaleType, float minFreq = 20.0f, float maxFreq = 20000.0f) const {
        const MusicalScale& scale = getScale(scaleType);
        float randomOctave = random(0, 4); // 0-3 octaves
        float baseFreq = scale.getRandomNoteFrequency(random(0.0f, 1.0f));
        float freq = baseFreq * pow(2.0f, randomOctave);
        return constrain(freq, minFreq, maxFreq);
    }
};

namespace ScaleUtils {
    inline const char* getScaleName(ScaleType type) {
        return ScaleManager::getInstance().getScale(type).getName();
    }
}

#endif // SCALES_H