#pragma once

#include <cstdint>
#include <cstddef> // Required for size_t
#include <array>
#include <vector>



class VM {
public:
    VM();

    void load_program(const std::vector<uint8_t>& program);
    void run();


private:
    std::array<uint8_t, 2> registers; // Two 8 bit registers
    std::vector<uint8_t> memory; // Holds loaded program
    size_t ip; // Instruction pointer

};   