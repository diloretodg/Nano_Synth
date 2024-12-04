// src/utils/PresetManager.h
class PresetManager {
private:
    static std::array<uint8_t, 512> presetBuffer;
    static constexpr size_t EEPROM_START_ADDRESS = 0;
    static constexpr size_t PRESET_SIZE = sizeof(Preset);
    static constexpr size_t MAX_PRESETS = 16;
    
    // Wear leveling
    static constexpr uint16_t WEAR_LEVEL_ADDRESSES[EEPROM_WEAR_LEVEL_BLOCKS] = {0, 128, 256, 384};
    uint8_t currentWearBlock = 0;
