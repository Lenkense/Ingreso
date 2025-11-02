#include "UnitVector.hpp"

std::string UnitVector::calculateAnswer(){
    int squared = data[0] * data[0] + data[1] * data[1];
    char buffer[128];
    snprintf(buffer, sizeof(buffer), unitVectorFormat, data[0], data[1], squared);
    return std::string(buffer);
};

std::string UnitVector::calculateAnswerFromQuestion(std::smatch match){
    int x = std::stoi(match[1]);
    int y = std::stoi(match[2]);
    int squared = x * x + y * y;
    char buffer[128];
    snprintf(buffer, sizeof(buffer), unitVectorFormat, x, y, squared);
    return std::string(buffer);
}

void UnitVector::generateOptions(){
    char buffer[128];
    int correctLength = data[0] * data[0] + data[1] * data[1];
    int wrongLength = data[0] + data[1];
    wrongLength = wrongLength > 0 ? wrongLength : -wrongLength;
    snprintf(buffer, sizeof(buffer), unitVectorFormat, data[0], data[1], correctLength + rng.getInt(1,3));
    options[0] = std::string(buffer);
    snprintf(buffer, sizeof(buffer), unitVectorFormat, data[0], data[1], wrongLength);
    options[1] = std::string(buffer);
    snprintf(buffer, sizeof(buffer), unitVectorFormat, data[0], data[1], wrongLength + rng.getInt(1,3));
    options[2] = std::string(buffer);
}

std::string UnitVector::getQuestion(){
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
             std::to_string(data[0]).c_str(), std::to_string(data[1]).c_str());
    return std::string(buffer);
}