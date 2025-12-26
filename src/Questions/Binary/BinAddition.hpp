#include "Question.hpp"

#ifndef _BINADDITION_HPP_
#define _BINADDITION_HPP_

class BinAddition : public Question<BinAddition>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    inline constexpr static size_t WIDTH = 8;
public:
    std::string format() const override;
    inline constexpr static size_t DEFAULT_SIZE = 2 * WIDTH;
    inline constexpr static const char *FORMAT = "Sumar: %s + %s";
    inline constexpr static int MIN_INT = 0;
    inline constexpr static int MAX_INT = 1;
};

#endif