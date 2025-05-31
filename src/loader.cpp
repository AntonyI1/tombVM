#include "loader.hpp"
#include <fstream>
#include <stdexcept>



std::vector<uint8_t> load_binary(const std::string& filepath){
    std::ifstream file(filepath, std::ios::binary);
    if(!file){
        throw std::runtime_error("Failed to open binary file");
    }
    
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(file)), {});
}