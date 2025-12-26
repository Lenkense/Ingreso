#include <bitset>
#include "BinAddition.hpp"

std::string BinAddition::calculateAnswer(){
    std::bitset<WIDTH> a;
    std::bitset<WIDTH> b;
    for (int i = 0; i < WIDTH; i++) {
        a[WIDTH - 1 - i] = data[i];
        b[WIDTH - 1 - i] = data[i + WIDTH];
    }
    std::bitset<WIDTH + 1> answer(a.to_ulong() + b.to_ulong());
    return answer.to_string();
}

std::string BinAddition::calculateAnswerFromQuestion(std::smatch match){
    std::bitset<WIDTH> a(match[1].str());
    std::bitset<WIDTH> b(match[2].str());
    std::bitset<WIDTH + 1> answer(a.to_ulong() + b.to_ulong());
    return answer.to_string();
}

void BinAddition::generateOptions(){
    int numberOfWrongOptions = NUM_OF_OPTIONS - 1;
    int maxNumOfBitFlips = 3;
    std::bitset<WIDTH + 1> correctAnswer(calculateAnswer());
    std::vector<std::bitset<WIDTH + 1>> output;
    rng.bitsetOptions<WIDTH + 1>(numberOfWrongOptions,
            maxNumOfBitFlips, correctAnswer, output);
    for(int i = 0; i < numberOfWrongOptions; i++){
        options[i] = output[i].to_string();
    }
}

std::string BinAddition::getQuestion(){
    std::bitset<WIDTH> a;
    std::bitset<WIDTH> b;
    for (int i = 0; i < WIDTH; i++) {
        a[WIDTH - 1 - i] = data[i];
        b[WIDTH - 1 - i] = data[i + WIDTH];
    }
    char buffer[64] = "";
    snprintf(buffer, sizeof(buffer), FORMAT,
            a.to_string().c_str(), b.to_string().c_str());
    return buffer;
}

std::string BinAddition::format() const {
    return FORMAT;
}
