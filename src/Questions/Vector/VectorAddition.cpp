#include "VectorAddition.hpp"
#include "VectorPrint.hpp"

std::string VectorAddition::calculateAnswer() {
    std::vector<int> u(data.begin(), data.begin() + DIM);
    std::vector<int> v(data.begin() + DIM, data.begin() + 2 * DIM);
    std::vector<int> result(DIM);
    for(int i = 0; i < DIM; i++) {
        result[i] = u[i] + v[i];
    }
    return vectorToString(result);
}

std::string VectorAddition::calculateAnswerFromQuestion(std::smatch match) {
    std::vector<int> result(DIM);
    for(int i = 0; i < DIM; i++) {
        int u = std::stoi(match[i + 1]);
        int v = std::stoi(match[i + 1 + DIM]);
        result[i] = u + v;
    }
    return vectorToString(result);
}

void VectorAddition::generateOptions() {
    std::vector<int> u(data.begin(), data.begin() + DIM);
    std::vector<int> v(data.begin() + DIM, data.begin() + 2 * DIM);
    std::vector<int> wrongAnswer(DIM);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = u[i] - v[i];
    }
    options[0] = vectorToString(wrongAnswer);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = v[i] - u[i];
    }
    options[1] = vectorToString(wrongAnswer);
    for(int i = 0; i < DIM; i++) {
        wrongAnswer[i] = - v[i] - u[i];
    }
    options[2] = vectorToString(wrongAnswer);
}

std::string VectorAddition::getQuestion() {
    char buffer[128];
    std::vector<int> u(data.begin(), data.begin() + DIM);
    std::vector<int> v(data.begin() + DIM, data.begin() + 2 * DIM);
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(u).c_str(), vectorToString(v).c_str());
    return std::string(buffer);
}

std::string VectorAddition::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
            emptyVector(DIM).c_str(), emptyVector(DIM).c_str());
    return std::string(buffer);
}
