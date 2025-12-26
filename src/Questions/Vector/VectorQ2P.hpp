#include "Question.hpp"
#include "VectorQuestion.hpp"

#ifndef _VECTORQ2P_HPP_
#define _VECTORQ2P_HPP_

class VectorQ2P : public VectorQuestion<VectorQ2P>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    std::string format() const override;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 * DIM;
    inline const static char *FORMAT =
        "Calcular P a partir de Q = %s y el vector PQ = %s";
    inline constexpr static int MIN_INT = -10;
    inline constexpr static int MAX_INT = 10;
};

#endif