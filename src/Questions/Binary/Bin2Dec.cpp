#include <bitset>
#include <stdio.h>
#include <numeric>
#include "Bin2Dec.hpp"
#include "BinaryUtils.hpp"

std::string Bin2Dec::calculateAnswer(){
    return std::to_string(data[0]);
}

std::string Bin2Dec::calculateAnswerFromQuestion(std::smatch match){
    std::bitset<WIDTH> number(match[1].str());
    return std::to_string(number.to_ulong());
}

void Bin2Dec::generateOptions(){
    int numberOfWrongOptions = NUM_OF_OPTIONS - 1;
    int maxNumOfBitFlips = 3;
    std::bitset<WIDTH> correctAnswer(data[0]);
    std::vector<std::bitset<WIDTH>> output;
    bitsetOptions<WIDTH>(numberOfWrongOptions,
            maxNumOfBitFlips, correctAnswer, output);
    for(int i = 0; i < numberOfWrongOptions; i++){
        options[i] = std::to_string(output[i].to_ulong());
    }
}

std::string Bin2Dec::getQuestion(){
    std::bitset<WIDTH> number(data[0]);
    char result[64] = "";
    std::string trimmedNumber = removeLeadingZeros(number.to_string());
    snprintf(result, sizeof(result), FORMAT, trimmedNumber.c_str());
    return result;
}