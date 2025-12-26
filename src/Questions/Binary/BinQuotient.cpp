#include <bitset>
#include "BinQuotient.hpp"
#include "BinaryUtils.hpp"

std::string BinQuotient::calculateAnswer()
{
    std::bitset<2 * WIDTH> a;
    std::bitset<WIDTH> b;
    for (int i = 0; i < 2 * WIDTH; i++) {
        a[2 * WIDTH - 1 - i] = data[i];
    }
    for (int i = 0; i < WIDTH; i++) {
        b[WIDTH - 1 - i] = data[i + 2 * WIDTH];
    }
    std::bitset<WIDTH + 1> answer(a.to_ulong() / b.to_ulong());
    return removeLeadingZeros(answer.to_string());
}

std::string BinQuotient::calculateAnswerFromQuestion(std::smatch match)
{
    std::bitset<2 * WIDTH> a(match[1].str());
    std::bitset<WIDTH> b(match[2].str());
    std::bitset<WIDTH + 1> answer(a.to_ulong() / b.to_ulong());
    std::string answerStr = removeLeadingZeros(answer.to_string());
    return answerStr;
}

void BinQuotient::generateOptions()
{
    data[0] = 1; // Ensure dividend is greater than 1024
    data[2 * WIDTH] = 1; // Ensure divisor is greater than 16
    int numberOfWrongOptions = NUM_OF_OPTIONS - 1;
    int maxNumOfBitFlips = 3;
    std::bitset<WIDTH + 1> correctAnswer(calculateAnswer());
    std::vector<std::bitset<WIDTH + 1>> output;
    rng.bitsetOptions<WIDTH + 1>(numberOfWrongOptions,
            maxNumOfBitFlips, correctAnswer, output);
    for(int i = 0; i < numberOfWrongOptions; i++){
        options[i] = removeLeadingZeros(output[i].to_string());
    }
}

std::string BinQuotient::getQuestion()
{
    std::bitset<2 * WIDTH> a;
    std::bitset<WIDTH> b;
    for (int i = 0; i < 2 * WIDTH; i++) {
        a[2 * WIDTH - 1 - i] = data[i];
    }
    for (int i = 0; i < WIDTH; i++) {
        b[WIDTH - 1 - i] = data[i + 2 * WIDTH];
    }
    char buffer[64] = "";
    snprintf(buffer, sizeof(buffer), FORMAT,
            removeLeadingZeros(a.to_string()).c_str(), removeLeadingZeros(b.to_string()).c_str());
    return buffer;
}

std::string BinQuotient::format() const
{
    return FORMAT;
}
