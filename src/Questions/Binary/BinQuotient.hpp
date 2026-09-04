#include "Question.hpp"

#ifndef _BINQUOTIENT_HPP_
#define _BINQUOTIENT_HPP_

class BinQuotient : public Question<BinQuotient>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    virtual void initData() override;
    inline constexpr static size_t WIDTH = 5;
public:
    inline constexpr static size_t DEFAULT_SIZE = 3 * WIDTH;
    inline constexpr static const char *FORMAT = "Encontrar el cociente de %s / %s";
    inline constexpr static int MIN_INT = 0;
    inline constexpr static int MAX_INT = 1;
};

#endif