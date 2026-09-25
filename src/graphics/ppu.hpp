#include "memory.hpp"

Memory::Memory() {
    reset();
}

void Memory::reset() {
    internal_ram_.fill(0);
    vram_.fill(0);
    oam_.fill(0);
    wram_.fill(0);
    rom_.clear();
}

void Memory::load_rom(const std::vector<std::uint8_t>& rom) {
    rom_ = rom;
}

std::uint8_t Memory::read_u8(std::uint32_t address) const {
    if (address >= 0x08000000 && address < 0x08000000 + static_cast<std::uint32_t>(rom_.size())) {
        return rom_[address - 0x08000000];
    }

    if (address >= 0x02000000 && address < 0x02000000 + internal_ram_.size()) {
        return internal_ram_[address - 0x02000000];
    }

    if (address >= 0x06000000 && address < 0x06000000 + vram_.size()) {
        return vram_[address - 0x06000000];
    }

    if (address >= 0x03000000 && address < 0x03000000 + wram_.size()) {
        return wram_[address - 0x03000000];
    }

    return 0;
}

std::uint16_t Memory::read_u16(std::uint32_t address) const {
    std::uint16_t value = static_cast<std::uint16_t>(read_u8(address));
    value |= static_cast<std::uint16_t>(read_u8(address + 1)) << 8;
    return value;
}

std::uint32_t Memory::read_u32(std::uint32_t address) const {
    std::uint32_t value = static_cast<std::uint32_t>(read_u8(address));
    value |= static_cast<std::uint32_t>(read_u8(address + 1)) << 8;
    value |= static_cast<std::uint32_t>(read_u8(address + 2)) << 16;
    value |= static_cast<std::uint32_t>(read_u8(address + 3)) << 24;
    return value;
}

void Memory::write_u8(std::uint32_t address, std::uint8_t value) {
    if (address >= 0x02000000 && address < 0x02000000 + internal_ram_.size()) {
        internal_ram_[address - 0x02000000] = value;
        return;
    }

    if (address >= 0x06000000 && address < 0x06000000 + vram_.size()) {
        vram_[address - 0x06000000] = value;
        return;
    }

    if (address >= 0x03000000 && address < 0x03000000 + wram_.size()) {
        wram_[address - 0x03000000] = value;
        return;
    }
}

void Memory::write_u16(std::uint32_t address, std::uint16_t value) {
    write_u8(address, static_cast<std::uint8_t>(value & 0xFF));
    write_u8(address + 1, static_cast<std::uint8_t>((value >> 8) & 0xFF));
}

void Memory::write_u32(std::uint32_t address, std::uint32_t value) {
    write_u8(address, static_cast<std::uint8_t>(value & 0xFF));
    write_u8(address + 1, static_cast<std::uint8_t>((value >> 8) & 0xFF));
    write_u8(address + 2, static_cast<std::uint8_t>((value >> 16) & 0xFF));
    write_u8(address + 3, static_cast<std::uint8_t>((value >> 24) & 0xFF));
}
