#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "CLIParser.hpp"
#include "TextFormat.hpp"
#include "Question.hpp"
#include "QuestionBase.hpp"
#include "Bin2Dec.hpp"
#include "Dec2Bin.hpp"
#include "BinAddition.hpp"
#include "BinSubstraction.hpp"
#include "BinMultiplication.hpp"
#include "BinQuotient.hpp"
#include "BinRemainder.hpp"
#include "VectorPQ.hpp"
#include "VectorP2Q.hpp"
#include "VectorQ2P.hpp"
#include "VectorAddition.hpp"
#include "ScalarMultiplication.hpp"
#include "LinearCombination.hpp"
#include "VectorLength.hpp"
#include "UnitVector.hpp"

int main(int argc, char *argv[]){
    CLIParser& parser = CLIParser::getInstance();
    parser.parse(argc, argv);
    int exampleQuestions = parser.getNumberOfQuestions();
    bool binary = parser.isBinaryEnabled();
    bool vector = parser.isVectorEnabled();
    TextFormat format = parser.getTextFormat();
    std::string outputFile = parser.getOutputFile();
    std::vector<std::string> questions;
    std::ostringstream stream;
    QuestionBase *generator;
    if (binary) {
        generator = &Bin2Dec::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &Dec2Bin::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &BinAddition::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &BinSubstraction::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &BinMultiplication::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &BinQuotient::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &BinRemainder::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
    }
    if (vector) {
        generator = &VectorPQ::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &VectorP2Q::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &VectorQ2P::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &VectorAddition::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &ScalarMultiplication::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &LinearCombination::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &VectorLength::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
        generator = &UnitVector::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            stream << question;
        }
    }
    if (outputFile.empty()){
        std::cout << stream.str();
    } else {
        std::istringstream iterate(stream.str());
        std::ostringstream questionStream;
        std::ostringstream answerStream;
        std::string line;
        std::string prefix = Bin2Dec::getInstance().getAnswerPrefix();
        int num_of_answers = 0;
        while(std::getline(iterate, line)){
            if(line.rfind(prefix, 0) == 0){
                num_of_answers++;
                answerStream << num_of_answers << ": " << line.substr(prefix.length()) << "\n";
            } else {
                questionStream << line << "\n";
            }
        }
        std::string extension = formatExtension(format);
        std::ofstream outputQuestion(outputFile + extension);
        outputQuestion << questionStream.str();
        outputQuestion.close();
        if(!answerStream.str().empty()){
            std::ofstream outputAnswer(outputFile + "_answers" + extension);
            outputAnswer << answerStream.str();
            outputAnswer.close();
        }
    }
    return 0;
}