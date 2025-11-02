#include "Question.hpp"

#ifndef _VECTORLENGTH_HPP_
#define _VECTORLENGTH_HPP_

class VectorLength : public Question<VectorLength>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    inline constexpr static size_t DIM = 2;
public:
    inline constexpr static size_t DEFAULT_SIZE = DIM;
    inline const static char *sqrtFormat = "\u221A(%i)";
    inline const static char *FORMAT =
        "Calcular el módulo del vector v donde: v = (%s, %s)";
    inline constexpr static int MIN_INT = -5;
    inline constexpr static int MAX_INT = 5;
};

#endif