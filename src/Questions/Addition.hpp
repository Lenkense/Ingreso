#include "Question.hpp"

#ifndef _ADDITION_HPP_
#define _ADDITION_HPP_

class Addition : public Question<Addition>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    inline constexpr static size_t WIDTH = 8;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 * WIDTH;
    inline const static char *FORMAT = "Sumar: %s + %s";
    inline constexpr static int MIN_INT = 0;
    inline constexpr static int MAX_INT = 1;
};

#endif