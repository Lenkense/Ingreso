#include "VectorP2Q.hpp"

std::string VectorP2Q::calculateAnswer() {
    std::string answer = "(";
    for(int i = 0; i < DIM; i++) {
        answer += std::to_string(data[i + DIM] + data[i]);
        if(i < DIM - 1) answer += ", ";
    }
    answer += ")";
    return answer;
}

std::string VectorP2Q::calculateAnswerFromQuestion(std::smatch match) {
    std::string answer = "(";
    for(int i = 0; i < DIM; i++) {
        int p = std::stoi(match[i + 1]);
        int pq = std::stoi(match[i + 1 + DIM]);
        answer += std::to_string(p + pq);
        if(i < DIM - 1) answer += ", ";
    }
    answer += ")";
    return answer;
}

void VectorP2Q::generateOptions() {
    std::string wrongAnswer = "(";
    for(int i = 0; i < DIM; i++) {
        wrongAnswer += std::to_string(data[i] - data[i + DIM]);
        if(i < DIM - 1) wrongAnswer += ", ";
    }
    wrongAnswer += ")";
    options[0] = wrongAnswer;
    wrongAnswer = "(";
    for(int i = 0; i < DIM; i++) {
        wrongAnswer += std::to_string(data[i + DIM] - data[i]);
        if(i < DIM - 1) wrongAnswer += ", ";
    }
    wrongAnswer += ")";
    options[1] = wrongAnswer;
    wrongAnswer = "(";
    for(int i = 0; i < DIM; i++) {
        wrongAnswer += std::to_string(- data[i] - data[i + DIM]);
        if(i < DIM - 1) wrongAnswer += ", ";
    }
    wrongAnswer += ")";
    options[2] = wrongAnswer;
}

std::string VectorP2Q::getQuestion() {
    char buffer[128];
    snprintf(buffer, sizeof(buffer), FORMAT,
             std::to_string(data[0]).c_str(), std::to_string(data[1]).c_str(),
             std::to_string(data[2]).c_str(), std::to_string(data[3]).c_str());
    return std::string(buffer);
}