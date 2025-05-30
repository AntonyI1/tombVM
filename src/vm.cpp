#include "vm.hpp"
#include <iostream>

VM::VM() : registers{0}, ip(0) {}

void VM::load_program(const std::vector<uint8_t>& program){
    memory = program;
}

void VM::run(){
    while(ip < memory.size()){
        uint8_t opcode = memory[ip++]; // Reads ip into opcode then increments

        switch(opcode){
            case 0x01: { // MOV R, value
                uint8_t reg = memory[ip++];
                uint8_t value = memory[ip++];
                registers[reg] = value;
                break;
            }
            case 0x02: { // ADD R, value
                uint8_t reg = memory[ip++];
                uint8_t value = memory[ip++];
                registers[reg] += value;
                break;
            }
            case 0x03: { // PRINT R
                uint8_t reg = memory[ip++];
                std::cout << "R" << (int)reg << " = " << (int)registers[reg] << std::endl;
                break;
            }
            case 0xFF: { // STOP
                return;
            }

            default: { // Error opcode
                std::cerr << "Unknown opcode : 0x" << std::hex << (int) opcode << std::dec << std::endl;
            }
        }
    }
}

