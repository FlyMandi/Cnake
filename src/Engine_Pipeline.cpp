#include "Engine_Pipeline.h"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace engine{

EnginePipeline::EnginePipeline(const std::string &vertFilepath, const std::string &fragFilepath){
    createGraphicsPipeline(vertFilepath, fragFilepath);
}

std::vector<char> EnginePipeline::readFile(const std::string &filepath){
    std::ifstream file{filepath, std::ios::ate | std::ios::binary};

    if (!file.is_open()){
        throw std::runtime_error("failed to open file: " + filepath);
    }

    size_t fileSize = static_cast<size_t>(file.tellg());
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);
    
    file.close();
    return buffer;
}

void EnginePipeline::createGraphicsPipeline(const std::string &vertFilepath, const std::string &fragFilepath){
    auto vertCode = readFile(vertFilepath);
    auto fragCode = readFile(fragFilepath);

    std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
    std::cout << "Frag Shader Code Size: " << fragCode.size() << '\n';
}

} //namespace engine