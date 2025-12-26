#include "Question.hpp"

#ifndef _BINSUBSTRACTION_HPP_
#define _BINSUBSTRACTION_HPP_

constexpr int absDiff(int x, int y){
    return (x > y) ? x - y : y - x;
}

class BinSubstraction : public Question<BinSubstraction>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    virtual void initData() override;
    inline constexpr static size_t WIDTH = 8;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 * WIDTH;
    inline constexpr static const char *FORMAT = "Restar: %s - %s";
    inline constexpr static int MIN_INT = 0;
    inline constexpr static int MAX_INT = 1;
};

#endif