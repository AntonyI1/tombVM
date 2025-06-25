#include "vm.hpp"
#include <iostream>

VM::VM() : registers{0}, ip(0), cmp_flag(false) {}

void VM::load_program(const std::vector<uint8_t>& program){
    memory = program;
}

void VM::run(){
    while(ip < memory.size()){
        uint8_t opcode = memory[ip++];

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
            case 0x04: { // JUMP address
                uint8_t address = memory[ip++];
                ip = address;
                break;
            }
            case 0x05: { // CMP R, value
                uint8_t reg = memory[ip++];
                uint8_t value = memory[ip++];
                cmp_flag = (registers[reg] == value);
                break;
            }
            case 0x06: { // JE address
                uint8_t address = memory[ip++];
                if (cmp_flag){
                    ip = address;
                }
                break;
            }
            case 0x07: {  // STORE R, address
                uint8_t reg = memory[ip++];
                uint8_t addr = memory[ip++];
                memory_array[addr] = registers[reg];
                break;
            }
            case 0x08: { // LOAD R, address
                uint8_t reg = memory[ip++];
                uint8_t addr = memory[ip++];
                registers[reg] = memory_array[addr];
                break;
            }
            case 0x09: { // PUSH R
                uint8_t reg = memory[ip++];
                stack.push(registers[reg]);
                break;
            }
            case 0x0A: { // POP R
                uint8_t reg = memory[ip++];
                if (!stack.empty()){
                    registers[reg] = stack.top();
                    stack.pop();
                }
                else{
                    std::cerr << "Stack underflow!\n";
                    return;
                }
                break;
            }
            case 0xFF: { // STOP
                return;
            }
            default: {
                std::cerr << "Unknown opcode: 0x" << std::hex << (int)opcode << std::dec << std::endl;
                return;
            }
        }
    }
}
