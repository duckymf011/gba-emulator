#ifndef GBA_EMULATOR_HPP
#define GBA_EMULATOR_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "audio/apu.hpp"
#include "cartridge/cartridge.hpp"
#include "cpu/cpu.hpp"
#include "graphics/ppu.hpp"
#include "input/input.hpp"
#include "memory/memory.hpp"

class Emulator {
public:
    Emulator();
    ~Emulator() = default;

    bool load_rom(const std::string& file_path);
    void run_frame();
    void reset();

    const Cartridge& cartridge() const { return cartridge_; }
    const PPU& ppu() const { return ppu_; }

private:
    CPU cpu_;
    Memory memory_;
    Cartridge cartridge_;
    PPU ppu_;
    Audio audio_;
    Input input_;
    std::uint32_t frame_count_ = 0;
};

#endif
