#include "TextFormat.hpp"

#ifndef _QUESTIONGENERATORBASE_HPP_
#define _QUESTIONGENERATORBASE_HPP_

class QuestionGeneratorBase{
public:
    QuestionGeneratorBase() {};
    virtual ~QuestionGeneratorBase() {};
    virtual std::vector<std::string> generateQuestions(int numberOfQuestions, TextFormat format) = 0;
};

#endif