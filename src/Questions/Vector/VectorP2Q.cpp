#include "VectorP2Q.hpp"
#include "VectorPrint.hpp"

std::string VectorP2Q::calculateAnswer() {
    std::vector<int> p(data.begin(), data.begin() + DIM);
    std::vector<int> pq(data.begin() + DIM, data.begin() + 2 * DIM);
    std::vector<int> q(DIM);
    std::string answer = "(";
    for(int i = 0; i < DIM; i++) {
        q[i] = pq[i] + p[i];
    }
    return vectorToString(q);
}

std::string VectorP2Q::calculateAnswerFromQuestion(std::smatch match) {
    std::vector<int> q(DIM);
    for(int i = 0; i < DIM; i++) {
        int p = std::stoi(match[i + 1]);
        int pq = std::stoi(match[i + 1 + DIM]);
        q[i] = p + pq;
    }
    return vectorToString(q);
}

void VectorP2Q::generateOptions() {
    std::vector<int> p(data.begin(), data.begin() + DIM);
    std::vector<int> pq(data.begin() + DIM, data.begin() + 2 * DIM);
    std::vector<int> wrongAnswer(DIM);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = p[i] - pq[i];
    }
    options[0] = vectorToString(wrongAnswer);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = pq[i] - p[i];
    }
    options[1] = vectorToString(wrongAnswer);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = - p[i] - pq[i];
    }
    options[2] = vectorToString(wrongAnswer);
}

std::string VectorP2Q::getQuestion() {
    char buffer[128];
    std::vector<int> p(data.begin(), data.begin() + DIM);
    std::vector<int> pq(data.begin() + DIM, data.begin() + 2 * DIM);
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(p).c_str(), vectorToString(pq).c_str());
    return std::string(buffer);
}

std::string VectorP2Q::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
            emptyVector(DIM).c_str(), emptyVector(DIM).c_str());
    return std::string(buffer);
}
