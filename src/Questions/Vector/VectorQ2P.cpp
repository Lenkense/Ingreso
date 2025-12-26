#include "VectorQ2P.hpp"
#include "VectorPrint.hpp"

std::string VectorQ2P::calculateAnswer() {
    std::vector<int> q(data.begin(), data.begin() + DIM);
    std::vector<int> pq(data.begin() + DIM, data.begin() + 2 * DIM);
    std::vector<int> p(DIM);
    for(int i = 0; i < DIM; i++) {
        p[i] = q[i] - pq[i];
    }
    return vectorToString(p);
}

std::string VectorQ2P::calculateAnswerFromQuestion(std::smatch match) {
    std::vector<int> p(DIM);
    for(int i = 0; i < DIM; i++) {
        int q = std::stoi(match[i + 1]);
        int pq = std::stoi(match[i + 1 + DIM]);
        p[i] = q - pq;
    }
    return vectorToString(p);
}

void VectorQ2P::generateOptions() {
    std::vector<int> q(data.begin(), data.begin() + DIM);
    std::vector<int> pq(data.begin() + DIM, data.begin() + 2 * DIM);
    std::vector<int> wrongAnswer(DIM);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = pq[i] - q[i];
    }
    options[0] = vectorToString(wrongAnswer);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = pq[i] + q[i];
    }
    options[1] = vectorToString(wrongAnswer);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = - pq[i] - q[i];
    }
    options[2] = vectorToString(wrongAnswer);
}

std::string VectorQ2P::getQuestion() {
    char buffer[128];
    std::vector<int> q(data.begin(), data.begin() + DIM);
    std::vector<int> pq(data.begin() + DIM, data.begin() + 2 * DIM);
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(q).c_str(), vectorToString(pq).c_str());
    return std::string(buffer);
}

std::string VectorQ2P::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
            emptyVector(DIM).c_str(), emptyVector(DIM).c_str());
    return std::string(buffer);
}
