#include "ScalarMultiplication.hpp"
#include "StringUtils.hpp"

std::string ScalarMultiplication::calculateAnswer() {
    int k = data[0];
    std::vector<int> v(data.begin() + 1, data.begin() + 1 + slice);
    std::vector<int> result(slice);
    for (int i = 0; i < slice; i++) {
        result[i] = k * v[i];
    }
    return vectorToString(result);
}

std::string ScalarMultiplication::calculateAnswerFromQuestion(std::smatch match) {
    std::vector<int> v(slice);
    int k = std::stoi(match[1]);
    for(int i = 0; i < slice; i++) {
        int a = std::stoi(match[i + 2]);
        v[i] = k * a;
    }
    return vectorToString(v);
}

void ScalarMultiplication::generateOptions() {
    slice = rng.getInt(2, DIM);
    int k = data[0];
    std::vector<int> v(data.begin() + 1, data.begin() + 1 + slice);
    std::vector<int> wrongVec(slice);
    for(int i = 0; i < slice; i++) {
        wrongVec[i] = v[i] + k;
    }
    options[0] = vectorToString(wrongVec);
    wrongVec.assign(slice, 0);
    for(int i = 0; i < slice; i++) {
        wrongVec[i] = -v[i] + k;
    }
    options[1] = vectorToString(wrongVec);
    for(int i = 0; i < slice; i++) {
        wrongVec[i] = -v[i] * k;
    }
    options[2] = vectorToString(wrongVec);
}

std::string ScalarMultiplication::getQuestion() {
    char buffer[128];
    int k = data[0];
    std::vector<int> v(data.begin() + 1, data.begin() + 1 + slice);
    snprintf(buffer, sizeof(buffer), FORMAT,
            std::to_string(k).c_str(),
            vectorToString(v).c_str());
    return std::string(buffer);
}

std::string ScalarMultiplication::format() const
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT, "%s",
            emptyVector(slice).c_str());
    return std::string(buffer);
}
