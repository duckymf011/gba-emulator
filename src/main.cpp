#include "cartridge.hpp"

#include <fstream>
#include <iostream>

bool Cartridge::load(const std::string& file_path) {
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open cartridge: " << file_path << std::endl;
        return false;
    }

    file.seekg(0, std::ios::end);
    const std::streamoff file_size = file.tellg();
    if (file_size <= 0) {
        std::cerr << "Cartridge is empty: " << file_path << std::endl;
        return false;
    }

    file.seekg(0, std::ios::beg);
    rom_.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

    std::cout << "Loaded ROM: " << file_path << " (" << rom_.size() << " bytes)" << std::endl;
    return true;
}
