#include "LinearCombination.hpp"
#include "VectorUtils.hpp"

std::string LinearCombination::calculateAnswer() {
    int k = data[0];
    int t = data[1];
    std::vector<int> u(data.begin() + 2, data.begin() + 2 + slice);
    std::vector<int> v(data.begin() + 2 + slice, data.begin() + 2 + 2 * slice);
    std::vector<int> result(slice);
    for(int i = 0; i < slice; i++) {
        result[i] = k * u[i] + t * v[i];
    }
    return vectorToString(result);
}

std::string LinearCombination::calculateAnswerFromQuestion(std::smatch match) {
    int k = std::stoi(match[1]);
    int t = std::stoi(match[2]);
    std::vector<int> result(slice);
    for(int i = 0; i < slice; i++) {
        int u = std::stoi(match[i + 3]);
        int v = std::stoi(match[i + 3 + slice]);
        result[i] = k * u + t * v;
    }
    return vectorToString(result);
}

void LinearCombination::generateOptions() {
    slice = rng.getInt(2, DIM);
    int k = data[0];
    int t = data[1];
    std::vector<int> u(data.begin() + 2, data.begin() + 2 + slice);
    std::vector<int> v(data.begin() + 2 + slice, data.begin() + 2 + 2 * slice);
    std::vector<int> wrongVec(slice);
    for(int i = 0; i < slice; i++) {
        wrongVec[i] = t * u[i] + k * v[i];
    }
    options[0] = vectorToString(wrongVec);
    for(int i = 0; i < slice; i++) {
        wrongVec[i] = t + u[i] + k + v[i];
    }
    options[1] = vectorToString(wrongVec);
    for(int i = 0; i < slice; i++) {
        wrongVec[i] = t - u[i] + k - v[i];
    }
    options[2] = vectorToString(wrongVec);
}

std::string LinearCombination::getQuestion() {
    char buffer[128];
    int k = data[0];
    int t = data[1];
    std::vector<int> u(data.begin() + 2, data.begin() + 2 + slice);
    std::vector<int> v(data.begin() + 2 + slice, data.begin() + 2 + 2 * slice);
    snprintf(buffer, sizeof(buffer), FORMAT,
            std::to_string(k).c_str(), std::to_string(t).c_str(),
            vectorToString(u).c_str(), vectorToString(v).c_str());
    return std::string(buffer);
}

std::string LinearCombination::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT, "%s", "%s",
            emptyVector(slice).c_str(), emptyVector(slice).c_str());
    return std::string(buffer);
}
