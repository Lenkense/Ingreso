#include "PQvector.hpp"
#include "VectorPrint.hpp"

std::string PQvector::calculateAnswer() {
    std::vector<int> p(data.begin(), data.begin() + DIM);
    std::vector<int> q(data.begin() + DIM, data.begin() + 2 * DIM);
    std::vector<int> pq(DIM);
    for(int i = 0; i < DIM; i++) {
        pq[i] = q[i] - p[i];
    }
    return vectorToString(pq);
}

std::string PQvector::calculateAnswerFromQuestion(std::smatch match) {
    std::vector<int> pq(DIM);
    for(int i = 0; i < DIM; i++) {
        int p = std::stoi(match[i + 1]);
        int q = std::stoi(match[i + 1 + DIM]);
        pq[i] = q - p;
    }
    return vectorToString(pq);
}

void PQvector::generateOptions() {
    std::vector<int> p(data.begin(), data.begin() + DIM);
    std::vector<int> q(data.begin() + DIM, data.begin() + 2 * DIM);
    std::vector<int> wrongAnswer(DIM);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = q[i] + p[i];
    }
    options[0] = vectorToString(wrongAnswer);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = p[i] - q[i];
    }
    options[1] = vectorToString(wrongAnswer);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = - p[i] - q[i];
    }
    options[2] = vectorToString(wrongAnswer);
}

std::string PQvector::getQuestion() {
    char buffer[128];
    std::vector<int> p(data.begin(), data.begin() + DIM);
    std::vector<int> q(data.begin() + DIM, data.begin() + 2 * DIM); 
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(p).c_str(), vectorToString(q).c_str());
    return std::string(buffer);
}

std::string PQvector::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT, emptyVector(DIM).c_str(),
             emptyVector(DIM).c_str());
    return std::string(buffer);
}
