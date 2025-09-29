#include "ScalarMultiplication.hpp"

std::string ScalarMultiplication::calculateAnswer() {
    std::string answer = "(";
    for(int i = 0; i < DIM; i++) {
        answer += std::to_string(data[i + 1] * data[0]);
        if(i < DIM - 1) answer += ", ";
    }
    answer += ")";
    return answer;
}

std::string ScalarMultiplication::calculateAnswerFromQuestion(std::smatch match) {
    std::string answer = "(";
    int k = std::stoi(match[1]);
    for(int i = 0; i < DIM; i++) {
        int v = std::stoi(match[i + 2]);
        answer += std::to_string(k * v);
        if(i < DIM - 1) answer += ", ";
    }
    answer += ")";
    return answer;
}

void ScalarMultiplication::generateOptions() {
    std::string wrongAnswer = "(";
    for(int i = 0; i < DIM; i++) {
        wrongAnswer += std::to_string(data[i + 1] - data[0]);
        if(i < DIM - 1) wrongAnswer += ", ";
    }
    wrongAnswer += ")";
    options[0] = wrongAnswer;
    wrongAnswer = "(";
    for(int i = 0; i < DIM; i++) {
        wrongAnswer += std::to_string(data[i + 1] + data[0]);
        if(i < DIM - 1) wrongAnswer += ", ";
    }
    wrongAnswer += ")";
    options[1] = wrongAnswer;
    wrongAnswer = "(";
    for(int i = 0; i < DIM; i++) {
        wrongAnswer += std::to_string(- data[i + 1] * - data[i + 0]);
        if(i < DIM - 1) wrongAnswer += ", ";
    }
    wrongAnswer += ")";
    options[2] = wrongAnswer;
}

std::string ScalarMultiplication::getQuestion() {
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
             std::to_string(data[0]).c_str(), std::to_string(data[1]).c_str(),
             std::to_string(data[2]).c_str(), std::to_string(data[3]).c_str());
    return std::string(buffer);
}