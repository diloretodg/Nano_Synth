// WirelessControl.h
#ifndef WIRELESS_CONTROL_H
#define WIRELESS_CONTROL_H

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include "Constants.h"
#include "GenerativeSequencer.h"

class WirelessControl {
private:
    AsyncWebServer server;
    GenerativeSequencer& sequencer;
    bool isEnabled;
    StaticJsonDocument<512> jsonBuffer;

public:
    WirelessControl(GenerativeSequencer& seq)
        : server(WEB_SERVER_PORT)
        , sequencer(seq)
        , isEnabled(false)
    {}

    void setup() {
        WiFi.softAP(DEFAULT_SSID, DEFAULT_PASSWORD);

        server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
            request->send(200, "text/html", getIndexHTML());
        });

        server.on("/api/sequence", HTTP_GET, [this](AsyncWebServerRequest *request) {
            String response = getSequenceJSON();
            request->send(200, "application/json", response);
        });

        server.begin();
        isEnabled = true;
    }

    void update() {
        if (!isEnabled) return;
    }

private:
    static String getIndexHTML() {
        return R"(
            <!DOCTYPE html>
            <html>
            <head>
                <title>Nano Synth Control</title>
                <meta name="viewport" content="width=device-width, initial-scale=1">
                <style>
                    body { font-family: Arial, sans-serif; margin: 20px; }
                    .control { margin: 10px 0; }
                </style>
            </head>
            <body>
                <h1>Nano Synth Control</h1>
                <div class="control">
                    <label>Volume: </label>
                    <input type="range" min="0" max="100" value="75" id="volume">
                </div>
                <div class="control">
                    <label>BPM: </label>
                    <input type="number" min="40" max="240" value="120" id="bpm">
                </div>
            </body>
            </html>
        )";
    }

    String getSequenceJSON() {
        StaticJsonDocument<1024> doc;
        JsonArray steps = doc.createNestedArray("steps");

        for (uint8_t i = 0; i < sequencer.getCurrentLength(); i++) {
            JsonObject step = steps.createNestedObject();
            const SequenceStep& seqStep = sequencer.getStep(i);
            step["frequency"] = seqStep.frequency;
            step["amplitude"] = seqStep.amplitude;
            step["waveform"] = static_cast<int>(seqStep.waveform);
            step["duration"] = seqStep.duration;
            step["gate"] = seqStep.gate;
        }

        String output;
        serializeJson(doc, output);
        return output;
    }
};

#endif // WIRELESS_CONTROL_H