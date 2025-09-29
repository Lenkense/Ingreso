#include "LinearCombination.hpp"

std::string LinearCombination::calculateAnswer() {
    std::string answer = "(";
    for(int i = 0; i < DIM; i++) {
        answer += std::to_string(data[0] * data[i + 2] + data[1] * data[i + 2 + DIM]);
        if(i < DIM - 1) answer += ", ";
    }
    answer += ")";
    return answer;
}

std::string LinearCombination::calculateAnswerFromQuestion(std::smatch match) {
    std::string answer = "(";
    int k = std::stoi(match[1]);
    int t = std::stoi(match[2]);
    for(int i = 0; i < DIM; i++) {
        int u = std::stoi(match[i + 3]);
        int v = std::stoi(match[i + 3 + DIM]);
        answer += std::to_string(k * u  + t * v);
        if(i < DIM - 1) answer += ", ";
    }
    answer += ")";
    return answer;
}

void LinearCombination::generateOptions() {
    //TODO fix bug options, is generating bad ones
    std::string wrongAnswer = "(";
    for(int i = 0; i < DIM; i++) {
        wrongAnswer += std::to_string( - data[0] * data[i + 2] -  data[1] * data[i + 2 + DIM]);
        if(i < DIM - 1) wrongAnswer += ", ";
    }
    wrongAnswer += ")";
    options[0] = wrongAnswer;
    wrongAnswer = "(";
    for(int i = 0; i < DIM; i++) {
        wrongAnswer += std::to_string(data[0] + data[i + 2] + data[1] + data[i + 2 + DIM]);
        if(i < DIM - 1) wrongAnswer += ", ";
    }
    wrongAnswer += ")";
    options[1] = wrongAnswer;
    wrongAnswer = "(";
    for(int i = 0; i < DIM; i++) {
        wrongAnswer += std::to_string(- data[0] - data[i + 2] - data[1] - data[i + 2 + DIM]);
        if(i < DIM - 1) wrongAnswer += ", ";
    }
    wrongAnswer += ")";
    options[2] = wrongAnswer;
}

std::string LinearCombination::getQuestion() {
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
             std::to_string(data[0]).c_str(), std::to_string(data[1]).c_str(),
             std::to_string(data[1]).c_str(), std::to_string(data[2]).c_str(),
             std::to_string(data[4]).c_str(), std::to_string(data[5]).c_str());
    return std::string(buffer);
}