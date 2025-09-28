#include <bitset>
#include <stdio.h>
#include <numeric>
#include "Bin2Dec.hpp"

void Bin2Dec::initData(){
    for(int i = 0; i < DEFAULT_SIZE; i++){
        data[i] = rng.getInt(MIN_INT, MAX_INT);
    }
}

std::string Bin2Dec::calculateAnswer(){
    return std::to_string(data[0]);
}

std::string Bin2Dec::calculateAnswerFromQuestion(std::smatch match){
    std::bitset<WIDTH> number(match[1].str());
    return std::to_string(number.to_ulong());
}

//TODO generate options bitset should be in PRNG.hpp
void Bin2Dec::generateOptions(){
    int numberOfWrongOptions = NUM_OF_OPTIONS - 1;
    int maxNumOfBitFlips = 3;
    std::bitset<WIDTH> correctAnswer(data[0]);
    std::vector<std::bitset<WIDTH>> output;
    rng.bitsetOptions<WIDTH>(numberOfWrongOptions,
            maxNumOfBitFlips, correctAnswer, output);
    for(int i = 0; i < numberOfWrongOptions; i++){
        options[i] = std::to_string(output[i].to_ulong());
    }
}

std::string Bin2Dec::getQuestion(){
    std::bitset<WIDTH> number(data[0]);
    char result[64] = "";
    snprintf(result, sizeof(result), FORMAT, number.to_string().c_str());
    return result;
}