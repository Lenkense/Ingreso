#include "Question.hpp"

#ifndef _EXAMPLEMULTIPLICATION_HPP_
#define _EXAMPLEMULTIPLICATION_HPP_

class ExampleMultiplication : public Question<ExampleMultiplication>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2;
    inline const static char *FORMAT = "Multiply the following numbers: %s * %s";
    inline constexpr static int MIN_INT = 1;
    inline constexpr static int MAX_INT = 9;
};

#ifdef _EXAMPLEMULTIPLICATION_IMPLEMENTATION_

std::string ExampleMultiplication::calculateAnswer(){
    return std::to_string(data[0] * data[1]);
}

std::string ExampleMultiplication::calculateAnswerFromQuestion(std::smatch match){
    int a = std::stoi(match[1]);
    int b = std::stoi(match[2]);
    return std::to_string(a * b);
}

void ExampleMultiplication::generateOptions() {
    options[0] = std::to_string(data[0] * data[1] + rng.getInt(-2, 2));
    options[1] = std::to_string(data[0] * data[1] + rng.getInt(-2, 2));
    options[2] = std::to_string(data[0] * data[1] + rng.getInt(-2, 2));
}

std::string ExampleMultiplication::getQuestion(){
    char buffer[64];
    snprintf(buffer, sizeof(buffer), FORMAT,
             std::to_string(data[0]).c_str(), std::to_string(data[1]).c_str());
    return std::string(buffer);
}

#endif

#endif