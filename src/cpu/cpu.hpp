#ifndef GBA_CPU_HPP
#define GBA_CPU_HPP

#include <cstdint>

#include "memory/memory.hpp"

class CPU {
public:
    CPU();
    void reset();
    void step(Memory& memory);

    std::uint32_t pc() const { return pc_; }

private:
    void execute_instruction(std::uint32_t instruction, Memory& memory);

    std::uint32_t registers_[16]{};
    std::uint32_t pc_ = 0x08000000;
    std::uint32_t cpsr_ = 0;
    std::uint32_t cycles_ = 0;
};

#endif
