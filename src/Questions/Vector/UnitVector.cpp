#include "UnitVector.hpp"
#include "VectorPrint.hpp"

std::string UnitVector::calculateAnswer(){
    int squared = 0;
    std::vector<int> values(data.begin(), data.begin() + DIM);
    std::string answer = vectorToString(values);
    for (size_t i = 0; i < DIM; i++){
        squared += values[i] * values[i];
    }
    answer += " / " + sqrtToString(squared);
    return answer;
};

std::string UnitVector::calculateAnswerFromQuestion(std::smatch match){
    int squared = 0;
    std::vector<int> values(DIM);
    for( size_t i = 0; i < DIM; i++){
        int value = std::stoi(match[i + 1]);
        values[i] = value;
        squared += value * value;
    }
    return vectorToString(values) + " / " + sqrtToString(squared);
}

void UnitVector::generateOptions(){
    int squared = 0;
    int linear = 0;
    int absolute = 0;
    std::vector<int> values(data.begin(), data.begin() + DIM);
    for (size_t i = 0; i < DIM; i++){
        squared += values[i] * values[i];
        linear += values[i];
        absolute += values[i] > 0 ? values[i] : -values[i];
    }
    linear = linear > 0 ? linear : -linear;
    linear = linear == 0 ? 1 : linear;  
    squared += rng.getInt(-3,3);
    options[0] = vectorToString(values) + " / " + sqrtToString(squared);
    options[1] = vectorToString(values) + " / " + sqrtToString(linear);
    options[2] = vectorToString(values) + " / " + sqrtToString(absolute);
}

std::string UnitVector::getQuestion(){
    char buffer[128];
    std::vector<int> values(data.begin(), data.begin() + DIM);
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(values).c_str());
    return std::string(buffer);
}

std::string UnitVector::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
            emptyVector(DIM).c_str());
    return std::string(buffer);
}
