#include "Question.hpp"

#ifndef _VECTORPQ_HPP_
#define _VECTORPQ_HPP_

class VectorPQ : public Question<VectorPQ>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    std::string format() const override;
    inline constexpr static size_t DIM = 4;
    inline static size_t slice;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 * DIM;
    inline const static char *FORMAT =
        "Calcular el vector PQ donde: P = %s y Q = %s";
    inline constexpr static int MIN_INT = -10;
    inline constexpr static int MAX_INT = 10;
};

#endif