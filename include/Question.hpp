#include <iostream>
#include <set>
#include <regex>
#include "PRNG.hpp"
#include "Singleton.hpp"

#ifndef _QUESTION_HPP_
#define _QUESTION_HPP_

template <typename Derived>
class Question : public Singleton<Derived>{
    friend class Singleton<Derived>;
protected:
    const static int NUM_OF_OPTIONS = 4;
    static PRNG& rng;
    std::vector<int> data;
    std::string options[NUM_OF_OPTIONS];
    int answer;

    Question() : data(Derived::DEFAULT_SIZE) {}
    virtual ~Question() {}

    void initData() {
        for (int i = 0; i < Derived::DEFAULT_SIZE; i++) {
            data[i] = rng.getInt(Derived::MIN_INT, Derived::MAX_INT);
        }
    }

    void insertAnswer() {
        int lastOption = NUM_OF_OPTIONS - 1;
        rng.shuffle(options, options + lastOption);
        if (answer != lastOption){
            options[lastOption] = options[answer];
        }
        options[answer] = calculateAnswer();
    }

     void blooketFormat(std::ostream& stream){
        std::string question = getQuestion();
        std::string endOfField = ",";
        stream << question << endOfField;
        for(auto option: options){
            stream << option << endOfField;
        }
        stream << 300 << endOfField;
        stream << answer + 1 << std::endl;
    }

    bool isNotValidQuestion(){
        std::set<std::string> diffOptions{std::begin(options), std::end(options)};
        if (diffOptions.size() != NUM_OF_OPTIONS){
            return false;
        }
        std::string format(Derived::FORMAT);
        // Escape all regex special characters in format string
        std::regex special(R"([.^$|()\[\]{}*+?\\])");
        format = std::regex_replace(format, special, "\\$&");
        std::regex target("%s");
        format = std::regex_replace(format, target, "(.*)");
        std::regex regex(format);
        std::smatch match;
        std::string question = getQuestion();
        std::regex_match(question, match, regex);
        std::string correctOption = calculateAnswerFromQuestion(match);
        for(int i = 0; i < NUM_OF_OPTIONS; i++){
            if((options[i] == correctOption) != (i == answer)){
                return false;
            }
        }
        return true;
    }

   // This is the API that your classes should implement
    virtual std::string calculateAnswer() = 0;
    virtual std::string calculateAnswerFromQuestion(std::smatch match) = 0;
    virtual void generateOptions() = 0;
    virtual std::string getQuestion() = 0;

public:
    std::string generateQuestion(){
        std::ostringstream outstream;
        bool validQuestion = false;
        while (!validQuestion) {
            initData();
            answer = rng.getInt(0,NUM_OF_OPTIONS - 1);
            generateOptions();
            insertAnswer();
            validQuestion = isNotValidQuestion();
        }
        //TODO: Maybe not hardcode blooket as the only option
        blooketFormat(outstream);
        return outstream.str();
    }

    std::vector<std::string> generateQuestions(int n){
        std::vector<std::string> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = generateQuestion();
        }
        return result;
    }

};

template <typename Derived>
PRNG& Question<Derived>::rng = PRNG::getInstance();

#endif