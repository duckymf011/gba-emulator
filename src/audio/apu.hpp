#include "ppu.hpp"

#include <algorithm>

PPU::PPU() {
    reset();
}

void PPU::reset() {
    framebuffer_.fill(0xFF000000);
    frame_counter_ = 0;
}

void PPU::render_frame() {
    // This is a stub renderer for the emulator shell.
    // Actual GBA rendering requires tile and sprite decomposition.
    std::fill(framebuffer_.begin(), framebuffer_.end(), 0xFF00FF00);
    ++frame_counter_;
}
