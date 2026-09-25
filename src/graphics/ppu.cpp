#ifndef GBA_PPU_HPP
#define GBA_PPU_HPP

#include <array>
#include <cstdint>

class PPU {
public:
    static constexpr int kScreenWidth = 240;
    static constexpr int kScreenHeight = 160;

    PPU();
    void reset();
    void render_frame();

    const std::array<std::uint32_t, kScreenWidth * kScreenHeight>& framebuffer() const {
        return framebuffer_;
    }

private:
    std::array<std::uint32_t, kScreenWidth * kScreenHeight> framebuffer_{};
    std::uint32_t frame_counter_ = 0;
};

#endif
