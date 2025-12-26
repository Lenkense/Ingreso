#include "VectorQ2P.hpp"
#include "VectorPrint.hpp"

std::string VectorQ2P::calculateAnswer() {
    std::vector<int> q(data.begin(), data.begin() + slice);
    std::vector<int> pq(data.begin() + slice, data.begin() + 2 * slice);
    std::vector<int> p(slice);
    for(int i = 0; i < slice; i++) {
        p[i] = q[i] - pq[i];
    }
    return vectorToString(p);
}

std::string VectorQ2P::calculateAnswerFromQuestion(std::smatch match) {
    std::vector<int> p(slice);
    for(int i = 0; i < slice; i++) {
        int q = std::stoi(match[i + 1]);
        int pq = std::stoi(match[i + 1 + slice]);
        p[i] = q - pq;
    }
    return vectorToString(p);
}

void VectorQ2P::generateOptions() {
    slice = PRNG::getInstance().getInt(2, DIM);
    std::vector<int> q(data.begin(), data.begin() + slice);
    std::vector<int> pq(data.begin() + slice, data.begin() + 2 * slice);
    std::vector<int> wrongAnswer(slice);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = pq[i] - q[i];
    }
    options[0] = vectorToString(wrongAnswer);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = pq[i] + q[i];
    }
    options[1] = vectorToString(wrongAnswer);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = - pq[i] - q[i];
    }
    options[2] = vectorToString(wrongAnswer);
}

std::string VectorQ2P::getQuestion() {
    char buffer[128];
    std::vector<int> q(data.begin(), data.begin() + slice);
    std::vector<int> pq(data.begin() + slice, data.begin() + 2 * slice);
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(q).c_str(), vectorToString(pq).c_str());
    return std::string(buffer);
}

std::string VectorQ2P::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
            emptyVector(slice).c_str(), emptyVector(slice).c_str());
    return std::string(buffer);
}
