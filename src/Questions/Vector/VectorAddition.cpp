#include "VectorAddition.hpp"
#include "VectorUtils.hpp"

std::string VectorAddition::calculateAnswer() {
    std::vector<int> u(data.begin(), data.begin() + slice);
    std::vector<int> v(data.begin() + slice, data.begin() + 2 * slice);
    std::vector<int> result(slice);
    for(int i = 0; i < slice; i++) {
        result[i] = u[i] + v[i];
    }
    return vectorToString(result);
}

std::string VectorAddition::calculateAnswerFromQuestion(std::smatch match) {
    std::vector<int> result(slice);
    for(int i = 0; i < slice; i++) {
        int u = std::stoi(match[i + 1]);
        int v = std::stoi(match[i + 1 + slice]);
        result[i] = u + v;
    }
    return vectorToString(result);
}

void VectorAddition::generateOptions() {
    slice = rng.getInt(2, DIM);
    std::vector<int> u(data.begin(), data.begin() + slice);
    std::vector<int> v(data.begin() + slice, data.begin() + 2 * slice);
    std::vector<int> wrongAnswer(slice);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = u[i] - v[i];
    }
    options[0] = vectorToString(wrongAnswer);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = v[i] - u[i];
    }
    options[1] = vectorToString(wrongAnswer);
    for(int i = 0; i < slice; i++) {
        wrongAnswer[i] = - v[i] - u[i];
    }
    options[2] = vectorToString(wrongAnswer);
}

std::string VectorAddition::getQuestion() {
    char buffer[128];
    std::vector<int> u(data.begin(), data.begin() + slice);
    std::vector<int> v(data.begin() + slice, data.begin() + 2 * slice);
    snprintf(buffer, sizeof(buffer), FORMAT,
            vectorToString(u).c_str(), vectorToString(v).c_str());
    return std::string(buffer);
}

std::string VectorAddition::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
            emptyVector(slice).c_str(), emptyVector(slice).c_str());
    return std::string(buffer);
}
