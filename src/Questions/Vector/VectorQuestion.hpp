#include "TextFormat.hpp"
#include "QuestionGenerator.hpp"

#ifndef _VECTORQUESTION_HPP_
#define _VECTORQUESTION_HPP_

template <typename Derived>
class VectorQuestion : public QuestionGenerator<Derived>{
protected:
    inline constexpr static size_t DIM = 4;
    inline static size_t slice;
public:
    virtual void initData() override {
        QuestionGenerator<Derived>::initData();
        slice = QuestionGenerator<Derived>::rng.getInt(2, DIM);
    };
};

#endif