#include "vm.hpp"
#include "loader.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: tombVM <binary_file.vmbin>\n";
        return 1;
    }

    try {
        VM vm;
        auto program = load_binary(argv[1]);
        vm.load_program(program);
        vm.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
