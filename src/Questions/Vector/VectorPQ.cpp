#include "VectorPQ.hpp"
#include "VectorPrint.hpp"

std::string VectorPQ::calculateAnswer() {
    std::vector<int> p(data.begin(), data.begin() + slice);
    std::vector<int> q(data.begin() + slice, data.begin() + 2 * slice);
    std::vector<int> pq(slice);
    for(int i = 0; i < slice; i++) {
        pq[i] = q[i] - p[i];
    }
    return vectorToString(pq);
}

std::string VectorPQ::calculateAnswerFromQuestion(std::smatch match) {
    std::vector<int> pq(slice);
    for(int i = 0; i < slice; i++) {
        int p = std::stoi(match[i + 1]);
        int q = std::stoi(match[i + 1 + slice]);
        pq[i] = q - p;
    }
    return vectorToString(pq);
}

void VectorPQ::generateOptions() {
    slice = PRNG::getInstance().getInt(2, DIM);
    std::vector<int> p(data.begin(), data.begin() + slice);
    std::vector<int> q(data.begin() + slice, data.begin() + 2 * slice);
    std::vector<int> wrongAnswer(slice);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = q[i] + p[i];
    }
    options[0] = vectorToString(wrongAnswer);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = p[i] - q[i];
    }
    options[1] = vectorToString(wrongAnswer);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = - p[i] - q[i];
    }
    options[2] = vectorToString(wrongAnswer);
}

std::string VectorPQ::getQuestion() {
    char buffer[128];
    std::vector<int> p(data.begin(), data.begin() + slice);
    std::vector<int> q(data.begin() + slice, data.begin() + 2 * slice); 
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(p).c_str(), vectorToString(q).c_str());
    return std::string(buffer);
}

std::string VectorPQ::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT, emptyVector(slice).c_str(),
             emptyVector(slice).c_str());
    return std::string(buffer);
}
