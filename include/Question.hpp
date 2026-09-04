#include <iostream>
#include <string>

#ifndef _QUESTION_HPP_
#define _QUESTION_HPP_

class Question{
private:
    const std::string question;
    const std::vector<std::string> options;
    const int answer;
public:
    Question(std::string question,
            std::string options[], int numberOfOptions, int answer) : 
        question(std::move(question)),
        options(
            std::make_move_iterator(options),
            std::make_move_iterator(options + numberOfOptions)
        ),
        answer(answer)
    {}

    ~Question(){
    }

    const std::string getQuestion() const {
        return question;
    }

    const std::vector<std::string> getOptions() const {
        return options;
    }

    const std::string getTextAnswer() const {
        return options[answer];
    }

    const int getNumberAnswer() const {
        return answer;
    }
};
#endif