#include <bitset>
#include "BinMultiplication.hpp"
#include "BinaryUtils.hpp"

std::string BinMultiplication::calculateAnswer()
{
    std::bitset<WIDTH> a;
    std::bitset<WIDTH> b;
    for (int i = 0; i < WIDTH; i++) {
        a[WIDTH - 1 - i] = data[i];
        b[WIDTH - 1 - i] = data[i + WIDTH];
    }
    std::bitset<2 * WIDTH> answer(a.to_ulong() * b.to_ulong());
    return removeLeadingZeros(answer.to_string());
}

std::string BinMultiplication::calculateAnswerFromQuestion(std::smatch match)
{
    std::bitset<WIDTH> a(match[1].str());
    std::bitset<WIDTH> b(match[2].str());
    std::bitset<2 * WIDTH> answer(a.to_ulong() * b.to_ulong());
    std::string answerStr = removeLeadingZeros(answer.to_string());
    return answerStr;
}

void BinMultiplication::generateOptions()
{
    int numberOfWrongOptions = NUM_OF_OPTIONS - 1;
    int maxNumOfBitFlips = 3;
    std::bitset<2 * WIDTH> correctAnswer(calculateAnswer());
    std::vector<std::bitset<2 * WIDTH>> output;
    rng.bitsetOptions<2 * WIDTH>(numberOfWrongOptions,
            maxNumOfBitFlips, correctAnswer, output);
    for(int i = 0; i < numberOfWrongOptions; i++){
        options[i] = removeLeadingZeros(output[i].to_string());
    }
}

std::string BinMultiplication::getQuestion()
{
    std::bitset<WIDTH> a;
    std::bitset<WIDTH> b;
    for (int i = 0; i < WIDTH; i++) {
        a[WIDTH - 1 - i] = data[i];
        b[WIDTH - 1 - i] = data[i + WIDTH];
    }
    char buffer[64] = "";
    snprintf(buffer, sizeof(buffer), FORMAT,
            removeLeadingZeros(a.to_string()).c_str(), removeLeadingZeros(b.to_string()).c_str());
    return buffer;
}

void BinMultiplication::initData()
{
    Question::initData();
    data[0] = 1; // Ensure factors are greater than 16
    data[WIDTH] = 1; // Ensure factors are greater than 16
}
