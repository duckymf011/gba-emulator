#include "emulator.hpp"

#include <iostream>

Emulator::Emulator() {
    reset();
}

bool Emulator::load_rom(const std::string& file_path) {
    if (!cartridge_.load(file_path)) {
        return false;
    }

    memory_.load_rom(cartridge_.data());
    cpu_.reset();
    return true;
}

void Emulator::reset() {
    cpu_.reset();
    memory_.reset();
    ppu_.reset();
    audio_.reset();
    input_.reset();
    frame_count_ = 0;
    std::cout << "Emulator reset." << std::endl;
}

void Emulator::run_frame() {
    // This run loop is intentionally simplified. The ROM is not fully emulated yet,
    // but the project structure is in place for real instruction execution.
    for (int i = 0; i < 1000; ++i) {
        cpu_.step(memory_);
    }

    ppu_.render_frame();
    audio_.tick();
    ++frame_count_;
}
