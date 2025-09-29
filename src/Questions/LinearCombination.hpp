#include "Question.hpp"

#ifndef _LINEARCOMBINATION_HPP_
#define _LINEARCOMBINATION_HPP_

class LinearCombination : public Question<LinearCombination>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    inline constexpr static size_t DIM = 2;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 + 2 * DIM;
    inline const static char *FORMAT =
        "Calcular k.u + t.v a partir de k = %s, t = %s, u = (%s, %s) y v = (%s, %s)";
    inline constexpr static int MIN_INT = -10;
    inline constexpr static int MAX_INT = 10;
};

#endif