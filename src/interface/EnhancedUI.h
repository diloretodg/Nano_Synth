// EnhancedUI.h
#ifndef ENHANCED_UI_H
#define ENHANCED_UI_H

#include <Adafruit_SSD1306.h>
#include "Definitions.h"

class EnhancedUI {
public:
    void drawParameterPage(Adafruit_SSD1306& display);
    void drawSequencerView(Adafruit_SSD1306& display);
    void drawPerformanceInfo(Adafruit_SSD1306& display);
private:
    const char* getCurrentParameterName();
    int getCurrentParameterValue();
};

#endif
