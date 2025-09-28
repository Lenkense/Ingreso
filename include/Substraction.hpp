#include "Question.hpp"

#ifndef _SUBSTRACTION_HPP_
#define _SUBSTRACTION_HPP_

constexpr int absDiff(int x, int y){
    return (x > y) ? x - y : y - x;
}

class Substraction : public Question<Substraction>{
protected:
    void initData() override;
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    inline constexpr static size_t WIDTH = 8;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 * WIDTH;
    inline const static char *FORMAT = "Restar: %s - %s";
};

#endif