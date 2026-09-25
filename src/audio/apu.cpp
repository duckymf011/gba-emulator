#ifndef GBA_APU_HPP
#define GBA_APU_HPP

#include <cstdint>

class Audio {
public:
    Audio();
    void reset();
    void tick();

private:
    std::uint32_t sample_position_ = 0;
};

#endif
