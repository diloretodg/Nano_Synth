// EvolutionVisualizer.h
#ifndef EVOLUTION_VISUALIZER_H
#define EVOLUTION_VISUALIZER_H

#include <Adafruit_SSD1306.h>
#include "Definitions.h"

class EvolutionVisualizer {
private:
    Adafruit_SSD1306& display;

public:
    explicit EvolutionVisualizer(Adafruit_SSD1306& disp) : display(disp) {}

    void update(uint8_t currentStep, const SequenceStep* steps, uint8_t sequenceLength, const EvolutionParameters& params) {
        display.clearDisplay();
        
        // Draw sequence timeline
        const uint8_t timelineY = 32;
        const uint8_t stepWidth = display.width() / sequenceLength;
        
        for (uint8_t i = 0; i < sequenceLength; i++) {
            uint8_t x = i * stepWidth;
            uint8_t height = map(steps[i].amplitude * steps[i].velocity, 0, 127, 0, 24);
            
            // Draw step bar
            display.drawRect(x, timelineY - height, stepWidth - 1, height, SSD1306_WHITE);
            
            // Highlight current step
            if (i == currentStep) {
                display.fillRect(x, timelineY - height, stepWidth - 1, height, SSD1306_WHITE);
            }
        }
        
        // Draw evolution parameters
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);
        display.print(F("M:"));
        display.print(static_cast<int>(params.mutationRate * 100));
        display.print(F(" C:"));
        display.print(static_cast<int>(params.crossoverRate * 100));
        
        display.display();
    }
};

#endif // EVOLUTION_VISUALIZER_H