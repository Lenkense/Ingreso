#include <iostream>
#include <set>
#include <regex>
#include "PRNG.hpp"
#include "Singleton.hpp"
#include "QuestionBase.hpp"
#include "TextFormat.hpp"

#ifndef _QUESTION_HPP_
#define _QUESTION_HPP_

template <typename Derived>
class Question : public Singleton<Derived>, public QuestionBase {
    friend class Singleton<Derived>;
    friend class QuestionBase;
protected:
    const static int NUM_OF_OPTIONS = 4;
    static PRNG& rng;
    std::vector<int> data;
    std::string options[NUM_OF_OPTIONS];
    int answer;
    std::string answerPrefix = "%%%% Answer: ";

    Question() : data(Derived::DEFAULT_SIZE) {}
    virtual ~Question() {}

    virtual void initData() {
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

    virtual std::string format() const {
        return Derived::FORMAT;
    }

    bool isNotValidQuestion(){
        std::set<std::string> diffOptions{std::begin(options), std::end(options)};
        if (diffOptions.size() != NUM_OF_OPTIONS){
            return false;
        }

        std::string fmt = format();
        // Escape all regex special characters in format string
        std::regex special(R"([.^$|()\[\]{}*+?\\])");
        fmt = std::regex_replace(fmt, special, "\\$&");
        std::regex percentage(R"(%%)");
        fmt = std::regex_replace(fmt, percentage, "%");
        std::regex target("%s");
        fmt = std::regex_replace(fmt, target, "(.*)");
        std::regex regex(fmt);
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

    void blooketFormat(std::ostream& stream){
        std::string question = getQuestion();
        std::string endOfField = ",";
        stream << "\"" << question << "\"" << endOfField;
        for(auto option: options){
            stream << "\"" << option << "\"" << endOfField;
        }
        stream << 300 << endOfField;
        stream << answer + 1 << std::endl;
    }

    void latexNoOptionsFormat(std::ostream& stream){
        std::string text;
        text = "\\item " + getQuestion() + "\n";
        std::string correctOption = options[answer];
        text += answerPrefix + correctOption + "\n";
        //TODO: Handle special LaTeX characters in question and options
        std::regex re("√\\(([^)]*)\\)");
        text = std::regex_replace(text, re, "$\\sqrt{$1}$");
        stream << text;
    }

    void latexFormat(std::ostream& stream){
        std::string text;
        text = "\\item " + getQuestion() + "\n";
        std::string correctOption(1, 'a' + answer);
        text += answerPrefix + correctOption + "\n";
        text += "\\begin{enumerate}\n";
        for(auto option: options){
            text += "\\item " + option + "\n";
        }
        text += "\\end{enumerate}\n";
        //TODO: Handle special LaTeX characters in question and options
        std::regex re("√\\(([^)]*)\\)");
        text = std::regex_replace(text, re, "$\\sqrt{$1}$");
        stream << text;
    }

    void noOptionsFormat(std::ostream& stream){
        stream << getQuestion() << std::endl;
        stream << answerPrefix << options[answer] << "\n";
    }

    void plainTextFormat(std::ostream& stream){
        stream << getQuestion() << "\n";
        for(auto option: options){
            stream << option << "\n";
        }
        std::string correctOption(1, 'a' + answer);
        stream << answerPrefix << correctOption << "\n";
    }

   // This is the API that your classes should implement
    virtual std::string calculateAnswer() = 0;
    virtual std::string calculateAnswerFromQuestion(std::smatch match) = 0;
    virtual void generateOptions() = 0;
    virtual std::string getQuestion() = 0;

    std::string generateQuestion(TextFormat format){
        std::ostringstream outstream;
        bool validQuestion = false;
        while (!validQuestion) {
            initData();
            answer = rng.getInt(0,NUM_OF_OPTIONS - 1);
            generateOptions();
            insertAnswer();
            validQuestion = isNotValidQuestion();
        }
        switch(format){
            case LATEX:
                latexFormat(outstream);
                break;
            case LATEXNOOPTIONS:
                latexNoOptionsFormat(outstream);
                break;
            case BLOOKET:
                blooketFormat(outstream);
                break;
            case NOOPTIONS:
                noOptionsFormat(outstream);
                break;
            case PLAINTEXT:
                plainTextFormat(outstream);
                break;
            default:
                std::cerr << "Unknown format!" << std::endl;
                exit(1);
        }
        return outstream.str();
    }

public:
    std::vector<std::string> generateQuestions(int n, TextFormat format) override {
        std::vector<std::string> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = generateQuestion(format);
        }
        return result;
    }

    std::string getAnswerPrefix() const {
        return answerPrefix;
    }
};

template <typename Derived>
PRNG& Question<Derived>::rng = PRNG::getInstance();

#endif