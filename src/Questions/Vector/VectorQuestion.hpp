#include "TextFormat.hpp"
#include "Question.hpp"

#ifndef _VECTORQUESTION_HPP_
#define _VECTORQUESTION_HPP_

template <typename Derived>
class VectorQuestion : public Question<Derived>{
protected:
    inline constexpr static size_t DIM = 4;
    inline static size_t slice;
public:
    virtual void initData() override {
        Question<Derived>::initData();
        slice = Question<Derived>::rng.getInt(2, DIM);
    };
};

#endif