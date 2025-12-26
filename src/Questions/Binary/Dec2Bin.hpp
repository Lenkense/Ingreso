#include "Question.hpp"

#ifndef _DEC2BIN_HPP_
#define _DEC2BIN_HPP_

class Dec2Bin : public Question<Dec2Bin>{
public:
    inline constexpr static size_t DEFAULT_SIZE = 12;
    inline constexpr static const char *FORMAT = "Convertir %s a binario";
    inline constexpr static int MIN_INT = 0;
    inline constexpr static int MAX_INT = 1;
    std::string format() const override;
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
};

#endif