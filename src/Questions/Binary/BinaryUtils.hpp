#include <string>
#include <vector>
#include <bitset>
#include "PRNG.hpp"

#ifndef _BINARYUTILS_HPP_
#define _BINARYUTILS_HPP_

inline constexpr size_t const_log2(size_t n) {
    return (n <= 1) ? 1 : 1 + const_log2(n/2);
}

inline std::string removeLeadingZeros(const std::string& s) {
    size_t pos = s.find_first_not_of('0');
    return (pos == std::string::npos) ? "0" : s.substr(pos);
}

template <int N>
void flipBits(std::bitset<N>& input, std::bitset<N>& output, int numOfFlips){
    output = input;
    std::vector<int> range(N);
    std::vector<int> sample;
    std::iota(std::begin(range), std::end(range), 0);
    PRNG& rng = PRNG::getInstance();
    rng.sample(std::begin(range), std::end(range), sample, numOfFlips);
    for(int i = 0; i < numOfFlips; i++){
        output.flip(sample[i]);
    }
}

template <int N>
void bitsetOptions(int numberOfOptions, int maxBitFlips, std::bitset<N> input,
    std::vector<std::bitset<N>>& output){
    PRNG& rng = PRNG::getInstance();
    for(int i = 0; i < numberOfOptions; i++){
        int numOfBitFlips = rng.getInt(1, maxBitFlips);
        std::bitset<N> option;
        flipBits<N>(input, option, numOfBitFlips);
        output.push_back(option);
    }
}

#endif