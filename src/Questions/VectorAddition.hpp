#include "Question.hpp"

#ifndef _VECTORADDITION_HPP_
#define _VECTORADDITION_HPP_

class VectorAddition : public Question<VectorAddition>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    inline constexpr static size_t DIM = 2;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 * DIM;
    inline const static char *FORMAT =
        "\"Calcular u + v a partir de u = (%s, %s) y v = (%s, %s)\"";
    inline constexpr static int MIN_INT = -10;
    inline constexpr static int MAX_INT = 10;
};

#endif