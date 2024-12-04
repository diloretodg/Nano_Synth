// src/utils/PresetManager.h
class PresetManager {
private:
    static constexpr size_t EEPROM_START_ADDRESS = 0;
    static constexpr size_t PRESET_SIZE = sizeof(Preset);
    static constexpr size_t MAX_PRESETS = 8;
    static constexpr size_t BUFFER_SIZE = 32;
    std::array<uint8_t, BUFFER_SIZE> buffer;
