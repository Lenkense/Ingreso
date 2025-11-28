#include "Question.hpp"

#ifndef _SCALARMULTIPLICATION_HPP_
#define _SCALARMULTIPLICATION_HPP_

class ScalarMultiplication : public Question<ScalarMultiplication>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    inline constexpr static size_t DIM = 2;
public:
    inline constexpr static size_t DEFAULT_SIZE = DIM + 1;
    inline const static char *FORMAT =
        "Calcular k.v a partir de k = %s y v = (%s, %s)";
    inline constexpr static int MIN_INT = -7;
    inline constexpr static int MAX_INT = 7;
};

#endif