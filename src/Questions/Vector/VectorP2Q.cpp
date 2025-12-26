#include "VectorP2Q.hpp"
#include "StringUtils.hpp"

std::string VectorP2Q::calculateAnswer() {
    std::vector<int> p(data.begin(), data.begin() + slice);
    std::vector<int> pq(data.begin() + slice, data.begin() + 2 * slice);
    std::vector<int> q(slice);
    std::string answer = "(";
    for(int i = 0; i < slice; i++) {
        q[i] = pq[i] + p[i];
    }
    return vectorToString(q);
}

std::string VectorP2Q::calculateAnswerFromQuestion(std::smatch match) {
    std::vector<int> q(slice);
    for(int i = 0; i < slice; i++) {
        int p = std::stoi(match[i + 1]);
        int pq = std::stoi(match[i + 1 + slice]);
        q[i] = p + pq;
    }
    return vectorToString(q);
}

void VectorP2Q::generateOptions() {
    slice = rng.getInt(2, DIM);
    std::vector<int> p(data.begin(), data.begin() + slice);
    std::vector<int> pq(data.begin() + slice, data.begin() + 2 * slice);
    std::vector<int> wrongAnswer(slice);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = p[i] - pq[i];
    }
    options[0] = vectorToString(wrongAnswer);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = pq[i] - p[i];
    }
    options[1] = vectorToString(wrongAnswer);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = - p[i] - pq[i];
    }
    options[2] = vectorToString(wrongAnswer);
}

std::string VectorP2Q::getQuestion() {
    char buffer[128];
    std::vector<int> p(data.begin(), data.begin() + slice);
    std::vector<int> pq(data.begin() + slice, data.begin() + 2 * slice);
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(p).c_str(), vectorToString(pq).c_str());
    return std::string(buffer);
}

std::string VectorP2Q::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
            emptyVector(slice).c_str(), emptyVector(slice).c_str());
    return std::string(buffer);
}
