#include "UnitVector.hpp"

std::string UnitVector::calculateAnswer(){
    int squared = 0;
    std::string answer = "(";
    for (size_t i = 0; i < DIM; i++){
        squared += data[i] * data[i];
        answer += std::to_string(data[i]);
        if(i < DIM - 1) answer += ", ";
    }
    answer += ") / " + sqrtSymbol + "(" + std::to_string(squared) + ")";
    return answer;
};

std::string UnitVector::calculateAnswerFromQuestion(std::smatch match){
    int squared = 0;
    std::string answer = "(";
    for( size_t i = 0; i < DIM; i++){
        int value = std::stoi(match[i + 1]);
        squared += value * value;
        answer += std::to_string(data[i]);
        if(i < DIM - 1) answer += ", ";
    }
    answer += ") / " + sqrtSymbol + "(" + std::to_string(squared) + ")";
    return answer;
}

void UnitVector::generateOptions(){
    std::string vector = "(";
    int squared = 0;
    int linear = 0;
    int absolute = 0;
    for (size_t i = 0; i < DIM; i++){
        squared += data[i] * data[i];
        linear += data[i];
        absolute += data[i] > 0 ? data[i] : -data[i];
        vector += std::to_string(data[i]);
        if(i < DIM - 1) vector += ", ";
    }
    vector += ")";
    linear = linear > 0 ? linear : -linear;
    linear = linear == 0 ? 1 : linear;  
    squared += rng.getInt(1,3);
    options[0] = vector + sqrtSymbol + "(" + std::to_string(squared) + ")";
    options[1] = vector + sqrtSymbol + "(" + std::to_string(linear) + ")";
    options[2] = vector + sqrtSymbol + "(" + std::to_string(absolute) + ")";
}

std::string UnitVector::getQuestion(){
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
             std::to_string(data[0]).c_str(), std::to_string(data[1]).c_str());
    return std::string(buffer);
}