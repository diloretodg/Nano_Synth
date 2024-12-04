// SystemMonitor.h
#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include <Arduino.h>
#include "Constants.h"

class SystemMonitor {
private:
    unsigned long lastCheck;
    static constexpr unsigned long CHECK_INTERVAL = 1000;

    float cpuLoad;
    float temperature;
    size_t freeMemory;
    float peakCpuLoad;
    float peakTemperature;
    size_t minimumFreeMemory;

public:
    SystemMonitor()
        : lastCheck(0)
        , cpuLoad(0)
        , temperature(0)
        , freeMemory(0)
        , peakCpuLoad(0)
        , peakTemperature(0)
        , minimumFreeMemory(ESP.getFreeHeap())
    {}

    void checkSystem() {
        unsigned long currentTime = millis();
        if (currentTime - lastCheck < CHECK_INTERVAL) return;

        lastCheck = currentTime;
        updateCPULoad();
        updateTemperature();
        updateMemory();

        peakCpuLoad = max(peakCpuLoad, cpuLoad);
        peakTemperature = max(peakTemperature, temperature);
        minimumFreeMemory = min(minimumFreeMemory, freeMemory);

        checkCriticalConditions();
    }

    float getCPULoad() const { return cpuLoad; }
    float getTemperature() const { return temperature; }
    size_t getFreeMemory() const { return freeMemory; }
    float getPeakCPULoad() const { return peakCpuLoad; }
    float getPeakTemperature() const { return peakTemperature; }
    size_t getMinimumFreeMemory() const { return minimumFreeMemory; }

    void resetPeakValues() {
        peakCpuLoad = cpuLoad;
        peakTemperature = temperature;
        minimumFreeMemory = freeMemory;
    }

private:
    void updateCPULoad() {
        static unsigned long lastMicros = 0;
        static unsigned long idleTime = 0;

        unsigned long currentMicros = micros();
        unsigned long elapsed = currentMicros - lastMicros;
        idleTime = elapsed / 2;

        cpuLoad = 100.0f * (1.0f - (float)idleTime / (float)elapsed);
        lastMicros = currentMicros;
    }

    void updateTemperature() {
        temperature = temperatureRead();
    }

    void updateMemory() {
        freeMemory = ESP.getFreeHeap();
    }

    void checkCriticalConditions() {
        if (temperature > 80.0f || freeMemory < 10000 || cpuLoad > 90.0f) {
            // Handle critical conditions
        }
    }
};

#endif // SYSTEM_MONITOR_H