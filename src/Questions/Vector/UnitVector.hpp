#include "Question.hpp"
#include "VectorQuestion.hpp"

#ifndef _UNITVECTOR_HPP_
#define _UNITVECTOR_HPP_

class UnitVector : public VectorQuestion<UnitVector>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    std::string format() const override;
public:
    inline constexpr static size_t DEFAULT_SIZE = DIM;
    inline const static char *FORMAT =
        "Calcular el vector unitario de v = %s";
    inline constexpr static int MIN_INT = -5;
    inline constexpr static int MAX_INT = 5;
};

#endif