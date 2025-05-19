#include <json.hpp>
#include <fstream>
#include <iostream>

namespace Cori { namespace JSON {
    
using json = nlohmann::ordered_json;

json read(std::string filePath) {
    std::ifstream jsonFileStream("data/" + filePath);
    json data = json::parse(jsonFileStream);
    return data;
}

void write(json data, std::string filePath) {
    std::cout << "data/" + filePath << std::endl;
    std::ofstream jsonOut("data/" + filePath);
    jsonOut << std::setw(2) << data;
}

}}