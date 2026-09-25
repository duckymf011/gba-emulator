#ifndef GBA_INPUT_HPP
#define GBA_INPUT_HPP

#include <cstdint>

enum class Button {
    A,
    B,
    L,
    R,
    Up,
    Down,
    Left,
    Right,
    Start,
    Select
};

class Input {
public:
    Input();
    void reset();
    void set_button(Button button, bool pressed);
    bool is_pressed(Button button) const;

private:
    std::uint16_t key_state_ = 0;
};

#endif
