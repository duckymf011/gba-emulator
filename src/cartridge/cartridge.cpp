#ifndef GBA_CARTRIDGE_HPP
#define GBA_CARTRIDGE_HPP

#include <cstdint>
#include <string>
#include <vector>

class Cartridge {
public:
    Cartridge() = default;
    bool load(const std::string& file_path);
    bool loaded() const { return !rom_.empty(); }
    std::size_t size() const { return rom_.size(); }
    const std::vector<std::uint8_t>& data() const { return rom_; }

private:
    std::vector<std::uint8_t> rom_;
};

#endif
