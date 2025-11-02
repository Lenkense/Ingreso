#include "ExampleAddition.hpp"

std::string ExampleAddition::calculateAnswer(){
    return std::to_string(data[0] + data[1]);
}

std::string ExampleAddition::calculateAnswerFromQuestion(std::smatch match){
    int a = std::stoi(match[1]);
    int b = std::stoi(match[2]);
    return std::to_string(a + b);
}

void ExampleAddition::generateOptions() {
    options[0] = std::to_string(data[0] + data[1] + rng.getInt(-2, 2));
    options[1] = std::to_string(data[0] + data[1] + rng.getInt(-2, 2));
    options[2] = std::to_string(data[0] + data[1] + rng.getInt(-2, 2));
}

std::string ExampleAddition::getQuestion(){
    char buffer[64];
    snprintf(buffer, sizeof(buffer), FORMAT,
             std::to_string(data[0]).c_str(), std::to_string(data[1]).c_str());
    return std::string(buffer);
}