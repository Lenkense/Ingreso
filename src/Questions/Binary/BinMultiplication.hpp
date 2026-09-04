#include "Question.hpp"

#ifndef _BINMULTIPLICATION_HPP_
#define _BINMULTIPLICATION_HPP_

class BinMultiplication : public Question<BinMultiplication>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    virtual void initData() override;
    inline constexpr static size_t WIDTH = 5;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 * WIDTH;
    inline constexpr static const char *FORMAT = "Multiplicar: %s * %s";
    inline constexpr static int MIN_INT = 0;
    inline constexpr static int MAX_INT = 1;
};

#endif