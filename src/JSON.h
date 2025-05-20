#pragma once

#include <json.hpp>
#include <fstream>
#include <iostream>

namespace Cori { namespace JSON {
    
using json = nlohmann::ordered_json;

inline json read(std::string filePath) {
    std::ifstream jsonFileStream("data/" + filePath);
    json data = json::parse(jsonFileStream);
    return data;
}

inline void write(json data, std::string filePath) {
    std::cout << "data/" + filePath << std::endl;
    std::ofstream jsonOut("data/" + filePath);
    jsonOut << data;
}

}}