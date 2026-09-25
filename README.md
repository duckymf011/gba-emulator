# GBA Emulator

A Game Boy Advance emulator capable of running classic retro games like Mario & Luigi, Pokémon, and more.

## Features

- **ARM7TDMI CPU Emulation** - Full instruction set support
- **Memory Management** - BIOS, ROM, RAM, and I/O registers
- **Graphics (PPU)** - Background and sprite rendering
- **Audio (APU)** - Sound channel emulation
- **Input** - Keypad support for game controls
- **Game Cartridge Loading** - Support for .gba and .bin ROM files

## Open Source References

This project is inspired by and uses patterns from:
- [mGBA](https://github.com/mgba-emu/mgba) - Popular GBA emulator
- [SkyEmu](https://github.com/SkyTemple/skyemu) - Accurate multi-system emulator
- [Eggvance](https://github.com/jsmolka/eggvance) - C++ GBA emulator

## Architecture

```
src/
├── cpu/              # ARM7TDMI CPU core
├── memory/           # Memory management (BIOS, ROM, RAM, I/O)
├── graphics/         # PPU (pixel processing unit)
├── audio/            # APU (audio processing unit)
├── input/            # Keypad input handling
├── cartridge/        # ROM loading and management
└── emulator.cpp      # Main emulator loop
```

## Building

### Requirements
- C++17 or later
- CMake 3.10+
- SDL2 (for graphics/input)

### Build Instructions

```bash
mkdir build
cd build
cmake ..
make
```

## Running

```bash
./gba-emulator path/to/game.gba
```

## Supported Games

- Mario & Luigi series
- Pokémon series
- The Legend of Zelda series
- Kirby series
- And many more classic GBA titles

## Project Status

🚧 Under development - Core CPU and memory systems in progress

## License

MIT License
