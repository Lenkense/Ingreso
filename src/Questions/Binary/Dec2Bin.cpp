#include "Dec2Bin.hpp"

std::string Dec2Bin::calculateAnswer(){
    std::bitset<DEFAULT_SIZE> answer;
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        answer[DEFAULT_SIZE - 1 - i] = data[i];
    }
    return answer.to_string();
}

std::string Dec2Bin::calculateAnswerFromQuestion(std::smatch match){
    unsigned long number = std::atoi(match[1].str().c_str());
    std::bitset<DEFAULT_SIZE> answer(number);
    return answer.to_string();
}

void Dec2Bin::generateOptions(){
    int numberOfWrongOptions = NUM_OF_OPTIONS - 2;
    int maxNumOfBitFlips = 3;
    std::bitset<DEFAULT_SIZE> correctAnswer(calculateAnswer());
    std::vector<std::bitset<DEFAULT_SIZE>> output;
    rng.bitsetOptions<DEFAULT_SIZE>(numberOfWrongOptions,
            maxNumOfBitFlips, correctAnswer, output);
    for(int i = 0; i < numberOfWrongOptions; i++){
        options[i] = output[i].to_string();
    }
    options[2] = correctAnswer.to_string();
    std::reverse(options[1].begin(), options[1].end());
    std::reverse(options[2].begin(), options[2].end());
}

std::string Dec2Bin::getQuestion(){
    int power = 1;
    int result = 0;
    for (int i = DEFAULT_SIZE - 1; i > -1; i--) {
        result += power * data[i];
        power *= 2;
    }
    char buffer[64] = "";
    snprintf(buffer, sizeof(buffer), FORMAT, std::to_string(result).c_str());
    return buffer;
}

std::string Dec2Bin::format() const {
    return FORMAT;
}
