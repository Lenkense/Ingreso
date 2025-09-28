#include "Question.hpp"

#ifndef _BIN2DEC_HPP_
#define _BIN2DEC_HPP_

constexpr size_t const_log2(size_t n) {
    return (n <= 1) ? 1 : 1 + const_log2(n/2);
}

class Bin2Dec : public Question<Bin2Dec>{
public:
    inline constexpr static size_t DEFAULT_SIZE = 1;
    inline const static char *FORMAT = "Convertir %s a decimal";
protected:
    void initData() override;
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    inline constexpr static size_t MAX_INT = 3500;
    inline constexpr static size_t MIN_INT = 1500;
    inline constexpr static size_t WIDTH = const_log2(MAX_INT);
};

#endif