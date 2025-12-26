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

private:
    PRNG() : engine(std::random_device{}()){}
    std::mt19937 engine;
};

#endif