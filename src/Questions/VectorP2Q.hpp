#include "Question.hpp"

#ifndef _VECTORP2Q_HPP_
#define _VECTORP2Q_HPP_

class VectorP2Q : public Question<VectorP2Q>{
protected:
    std::string calculateAnswer() override;
    std::string calculateAnswerFromQuestion(std::smatch match) override;
    void generateOptions() override;
    std::string getQuestion() override;
    inline constexpr static size_t DIM = 2;
public:
    inline constexpr static size_t DEFAULT_SIZE = 2 * DIM;
    inline const static char *FORMAT =
        "\"Calcular Q a partir de P = (%s, %s) y el vector PQ = (%s, %s)\"";
    inline constexpr static int MIN_INT = -10;
    inline constexpr static int MAX_INT = 10;
};

#endif