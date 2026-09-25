#include "input.hpp"

Input::Input() {
    reset();
}

void Input::reset() {
    key_state_ = 0;
}

void Input::set_button(Button button, bool pressed) {
    const std::uint16_t bit = static_cast<std::uint16_t>(1u) << static_cast<int>(button);
    if (pressed) {
        key_state_ |= bit;
    } else {
        key_state_ &= static_cast<std::uint16_t>(~bit);
    }
}

bool Input::is_pressed(Button button) const {
    const std::uint16_t bit = static_cast<std::uint16_t>(1u) << static_cast<int>(button);
    return (key_state_ & bit) != 0;
}
