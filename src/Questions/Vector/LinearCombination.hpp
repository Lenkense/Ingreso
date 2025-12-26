#include "Question.hpp"

#ifndef _LINEARCOMBINATION_HPP_
#define _LINEARCOMBINATION_HPP_

class LinearCombination : public Question<LinearCombination>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    std::string format() const override;
    inline constexpr static size_t DIM = 4;
    inline static size_t slice;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 + 2 * DIM;
    inline const static char *FORMAT =
        "Calcular k.u + t.v a partir de k = %s, t = %s, u = %s y v = %s";
    inline constexpr static int MIN_INT = -5;
    inline constexpr static int MAX_INT = 5;
};

#endif