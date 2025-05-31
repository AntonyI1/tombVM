#include "vm.hpp"
#include "loader.hpp"


int main(){
    VM vm;

    auto program = load_binary("../examples/test1.vmbin");

    vm.load_program(program);
    vm.run();

    return 0;
};