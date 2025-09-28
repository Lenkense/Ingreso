#include "Question.hpp"

#ifndef _DEC2BIN_HPP_
#define _DEC2BIN_HPP_

class Dec2Bin : public Question<Dec2Bin>{
public:
    inline constexpr static size_t DEFAULT_SIZE = 12;
    inline const static char *FORMAT = "Convertir %s a binario";
protected:
    void initData() override;
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
};

#endif