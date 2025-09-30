#include "Question.hpp"

#ifndef _EXAMPLEADDITION_HPP_
#define _EXAMPLEADDITION_HPP_

class ExampleAddition : public Question<ExampleAddition>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2;
    inline const static char *FORMAT = "Add the following numbers: %s + %s";
    inline constexpr static int MIN_INT = 1;
    inline constexpr static int MAX_INT = 19;
};

#endif