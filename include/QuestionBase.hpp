#include "TextFormat.hpp"

#ifndef _QUESTIONBASE_HPP_
#define _QUESTIONBASE_HPP_

class QuestionBase{
public:
    QuestionBase() {};
    virtual ~QuestionBase() {};
    virtual std::vector<std::string> generateQuestions(int numberOfQuestions, TextFormat format) = 0;
};

#endif