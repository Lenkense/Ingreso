#include <random>
#include <algorithm>
#include <bitset>
#include "Singleton.hpp"

#ifndef _PRNG_HPP_
#define _PRNG_HPP_

class PRNG : public Singleton<PRNG>{
    friend class Singleton<PRNG>;
public:
    int getInt(int min, int max){
        std::uniform_int_distribution<int> dist(min, max);
        return dist(engine);
    }

    template <class RandomIt>
    void shuffle(RandomIt first, RandomIt last){
        std::shuffle(first, last, engine);
    }

    template <class PopulationIt, class SampleIt, class Distance>
    void sample(PopulationIt first, PopulationIt last, SampleIt& out, Distance n){
        std::sample(first, last, std::back_inserter(out), n, engine);
    }

    template <int N>
    void flipBits(std::bitset<N>& input, std::bitset<N>& output, int numOfFlips){
        output = input;
        std::vector<int> range(N);
        std::vector<int> sample;
        std::iota(std::begin(range), std::end(range), 0);
        PRNG::sample(std::begin(range), std::end(range), sample, numOfFlips);
        for(int i = 0; i < numOfFlips; i++){
            output.flip(sample[i]);
        }
    }

    template <int N>
    void bitsetOptions(int numberOfOptions, int maxBitFlips, std::bitset<N> input,
        std::vector<std::bitset<N>>& output){
        for(int i = 0; i < numberOfOptions; i++){
            int numOfBitFlips = PRNG::getInt(1, maxBitFlips);
            std::bitset<N> option;
            PRNG::flipBits<N>(input, option, numOfBitFlips);
            output.push_back(option);
        }
    }

private:
    PRNG() : engine(std::random_device{}()){}
    std::mt19937 engine;
};

#endif