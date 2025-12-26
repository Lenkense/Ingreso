#include "VectorLength.hpp"
#include "StringUtils.hpp"

std::string VectorLength::calculateAnswer(){
    int squared = 0;
    std::vector<int> values(data.begin(), data.begin() + slice);
    for (size_t i = 0; i < slice; i++){
        squared += values[i] * values[i];
    }
    return sqrtToString(squared);
};

std::string VectorLength::calculateAnswerFromQuestion(std::smatch match){
    int squared = 0;
    for( size_t i = 0; i < slice; i++){
        int value = std::stoi(match[i + 1]);
        squared += value * value;
    }
    return sqrtToString(squared);
}

void VectorLength::generateOptions(){
    slice = rng.getInt(2, DIM);
    int squared = 0;
    int linear = 0;
    int absolute = 0;
    std::vector<int> values(data.begin(), data.begin() + slice);
    for( size_t i = 0; i < slice; i++){
        squared += values[i] * values[i];
        linear += values[i];
        absolute += values[i] > 0 ? values[i] : -values[i];
    }
    linear = linear > 0 ? linear : -linear;
    linear = linear == 0 ? 1 : linear;
    squared += rng.getInt(-3,3);
    options[0] = sqrtToString(squared);
    options[1] = sqrtToString(linear);
    options[2] = sqrtToString(absolute);
}

std::string VectorLength::getQuestion(){
    char buffer[128];
    std::vector<int> values(data.begin(), data.begin() + slice);
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(values).c_str());
    return std::string(buffer);
}

std::string VectorLength::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
            emptyVector(slice).c_str());
    return std::string(buffer);
}
