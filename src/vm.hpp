#pragma once

#include <cstdint>
#include <cstddef>
#include <array>
#include <vector>
#include <stack>




class VM {
public:
    VM();

    void load_program(const std::vector<uint8_t>& program);
    void run();


private:
    std::array<uint8_t, 4> registers; // Four 32-bit registers: R0-R3
    std::vector<uint8_t> memory; // Holds loaded program
    std::array<int32_t, 1024> memory_array; // Fixed memory block for LOAD/STORE
    std::stack<int32_t> stack; // LIFO stack for PUSH/POP
    size_t ip; // Instruction pointer
    bool cmp_flag; // stores result of last CMP (equal or not)
};   