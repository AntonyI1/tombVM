#include "vm.hpp"

int main(){
    VM vm;

    // Fake program 
    std::vector<uint8_t> program = {
        0x01, 0x00, 0x05, // MOV R0, 5
        0x02, 0x00, 0x03, // ADD R0, 3
        0x03, 0x00, // PRINT R0
        0xFF // STOP

    };

    vm.load_program(program);
    vm.run();

    return 0;
};