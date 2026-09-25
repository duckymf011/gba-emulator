#include "apu.hpp"

Audio::Audio() {
    reset();
}

void Audio::reset() {
    sample_position_ = 0;
}

void Audio::tick() {
    ++sample_position_;
}
