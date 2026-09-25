#include "cpu.hpp"

#include <iostream>

CPU::CPU() {
    reset();
}

void CPU::reset() {
    for (auto& reg : registers_) {
        reg = 0;
    }
    pc_ = 0x08000000;
    cpsr_ = 0;
    cycles_ = 0;
}

void CPU::execute_instruction(std::uint32_t instruction, Memory& memory) {
    (void)memory;
    (void)instruction;

    // Placeholder implementation. This is intentionally minimal and serves as a scaffold.
    // Real GBA emulation needs a full ARM7TDMI instruction decoder.
    pc_ += 4;
    ++cycles_;
}

void CPU::step(Memory& memory) {
    std::uint32_t instruction = memory.read_u32(pc_);
    execute_instruction(instruction, memory);
}
