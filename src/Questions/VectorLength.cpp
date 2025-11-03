#include "VectorLength.hpp"

std::string VectorLength::calculateAnswer(){
    int squared = 0;
    for (size_t i = 0; i < DIM; i++){
        squared += data[i] * data[i];
    }
    std::string answer = "\"" + sqrtSymborl + "(";
    answer += std::to_string(squared) + ")\"";
    return answer;
};

std::string VectorLength::calculateAnswerFromQuestion(std::smatch match){
    int squared = 0;
    int vector[DIM];
    for( size_t i = 0; i < DIM; i++){
        vector[i] = std::stoi(match[i + 1]);
        squared += vector[i] * vector[i];
    }
    std::string answer = "\"" + sqrtSymborl + "(";
    answer += std::to_string(squared) + ")\"";
    return answer;
}

void VectorLength::generateOptions(){
    int squared = 0;
    int linear = 0;
    int absolute = 0;
    for( size_t i = 0; i < DIM; i++){
        squared += data[i] * data[i];
        linear += data[i];
        absolute += data[i] > 0 ? data[i] : -data[i];
    }
    linear = linear > 0 ? linear : -linear;
    linear = linear == 0 ? 1 : linear;
    std::string answer = "\"" + sqrtSymborl + "(";
    answer += std::to_string(squared + rng.getInt(-3,3)) + ")\"";
    options[0] = answer;
    answer = "\"" + sqrtSymborl + "(";
    answer += std::to_string(linear) + ")\"";
    options[1] = answer;
    answer = "\"" + sqrtSymborl + "(";
    answer += std::to_string(absolute) + ")\"";
    options[2] = answer;
}

std::string VectorLength::getQuestion(){
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
             std::to_string(data[0]).c_str(), std::to_string(data[1]).c_str());
    return std::string(buffer);
}