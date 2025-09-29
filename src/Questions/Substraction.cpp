#include <bitset>
#include "Substraction.hpp"

std::string Substraction::calculateAnswer(){
    std::bitset<WIDTH> a;
    std::bitset<WIDTH> b;
    for (int i = 0; i < WIDTH; i++) {
        a[WIDTH - 1 - i] = data[i];
        b[WIDTH - 1 - i] = data[i + WIDTH];
    }
    int x = a.to_ulong();
    int y = b.to_ulong();
    std::bitset<WIDTH> answer(absDiff(a.to_ulong(),  b.to_ulong()));
    return answer.to_string();
}

std::string Substraction::calculateAnswerFromQuestion(std::smatch match){
    std::bitset<WIDTH> a(match[1].str());
    std::bitset<WIDTH> b(match[2].str());
    std::bitset<WIDTH> answer(a.to_ulong() - b.to_ulong());
    return answer.to_string();
}

void Substraction::generateOptions(){
    int numberOfWrongOptions = NUM_OF_OPTIONS - 1;
    int maxNumOfBitFlips = 3;
    std::bitset<WIDTH> correctAnswer(calculateAnswer());
    std::vector<std::bitset<WIDTH>> output;
    rng.bitsetOptions<WIDTH>(numberOfWrongOptions,
            maxNumOfBitFlips, correctAnswer, output);
    for(int i = 0; i < numberOfWrongOptions; i++){
        options[i] = output[i].to_string();
    }
}

std::string Substraction::getQuestion(){
    std::bitset<WIDTH> a;
    std::bitset<WIDTH> b;
    for (int i = 0; i < WIDTH; i++) {
        a[WIDTH - 1 - i] = data[i];
        b[WIDTH - 1 - i] = data[i + WIDTH];
    }
    char buffer[64] = "";
    if(a.to_ulong() > b.to_ulong()){
        snprintf(buffer, sizeof(buffer), FORMAT,
                a.to_string().c_str(), b.to_string().c_str());
    } else{
        snprintf(buffer, sizeof(buffer), FORMAT,
                b.to_string().c_str(), a.to_string().c_str());
    }
    return buffer;
}