#include "Question.hpp"

#ifndef _EXAMPLEQUOTIENT_HPP_
#define _EXAMPLEQUOTIENT_HPP_

class ExampleQuotient : public Question<ExampleQuotient>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    void initData() override;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2;
    inline const static char *FORMAT = "Calculate the quotient of the following numbers: %s / %s";
    inline constexpr static int MIN_INT = 1;
    inline constexpr static int MAX_INT = 60;
};

#ifdef _EXAMPLEQUOTIENT_IMPLEMENTATION_

std::string ExampleQuotient::calculateAnswer(){
    return std::to_string(data[0] * data[1]);
}

std::string ExampleQuotient::calculateAnswerFromQuestion(std::smatch match){
    int a = std::stoi(match[1]);
    int b = std::stoi(match[2]);
    return std::to_string(a * b);
}

void ExampleQuotient::generateOptions() {
    options[0] = std::to_string(data[0] * data[1] + rng.getInt(-2, 2));
    options[1] = std::to_string(data[0] * data[1] + rng.getInt(-2, 2));
    options[2] = std::to_string(data[0] * data[1] + rng.getInt(-2, 2));
}

std::string ExampleQuotient::getQuestion(){
    char buffer[64];
    snprintf(buffer, sizeof(buffer), FORMAT,
             std::to_string(data[0]).c_str(), std::to_string(data[1]).c_str());
    return std::string(buffer);
}

void ExampleQuotient::initData(){
    Question::initData();
    data[1] = data[1] % 7 + 2; // Divisor between 2 and 9
    data[0] = data[0] - (data[0] % data[1]); // Ensure dividend is multiple of divisor
}

#endif

#endif