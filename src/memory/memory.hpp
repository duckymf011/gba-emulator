#ifndef GBA_MEMORY_HPP
#define GBA_MEMORY_HPP

#include <array>
#include <cstdint>
#include <vector>

class Memory {
public:
    Memory();
    void reset();
    void load_rom(const std::vector<std::uint8_t>& rom);

    std::uint8_t read_u8(std::uint32_t address) const;
    std::uint16_t read_u16(std::uint32_t address) const;
    std::uint32_t read_u32(std::uint32_t address) const;

    void write_u8(std::uint32_t address, std::uint8_t value);
    void write_u16(std::uint32_t address, std::uint16_t value);
    void write_u32(std::uint32_t address, std::uint32_t value);

private:
    static constexpr std::size_t kInternalRamSize = 0x8000;      // 32 KB
    static constexpr std::size_t kVideoRamSize = 0x18000;        // 96 KB
    static constexpr std::size_t kObjectAttrMemSize = 0x400;      // 1 KB
    static constexpr std::size_t kWorkRamSize = 0x40000;          // 256 KB

    std::array<std::uint8_t, kInternalRamSize> internal_ram_{};
    std::array<std::uint8_t, kVideoRamSize> vram_{};
    std::array<std::uint8_t, kObjectAttrMemSize> oam_{};
    std::array<std::uint8_t, kWorkRamSize> wram_{};
    std::vector<std::uint8_t> rom_;
};

#endif
