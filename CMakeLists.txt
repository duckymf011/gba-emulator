#include <iostream>
#include <string>

#include "emulator.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: gba-emulator <rom.gba>" << std::endl;
        std::cout << "This is a scaffold emulator project. Full GBA compatibility is still under development." << std::endl;
        return 1;
    }

    Emulator emulator;
    const std::string rom_path = argv[1];

    if (!emulator.load_rom(rom_path)) {
        std::cerr << "Unable to load ROM: " << rom_path << std::endl;
        return 2;
    }

    std::cout << "GBA emulator initialized. Running a simplified starter frame loop..." << std::endl;
    emulator.run_frame();
    std::cout << "Emulator loop finished." << std::endl;
    return 0;
}
