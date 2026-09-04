#include "Question.hpp"
#include "VectorQuestion.hpp"

#ifndef _VECTORPQ_HPP_
#define _VECTORPQ_HPP_

class VectorPQ : public VectorQuestion<VectorPQ>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    std::string format() const override;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 * DIM;
    inline const static char *FORMAT =
        "Calcular el vector PQ donde: P = %s y Q = %s";
    inline constexpr static int MIN_INT = -10;
    inline constexpr static int MAX_INT = 10;
};

#endif