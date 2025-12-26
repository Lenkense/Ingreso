#include <iostream>
#include <cstring>
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

void showHelp(std::string programName){
    std::cout << "Generates a set of example questions for various question types." << std::endl;
    std::cout << "Usage: " << programName << " [number_of_questions] [FORMAT]" << std::endl;
    std::cout << "If number_of_questions is not provided, defaults to 100." << std::endl;
    std::cout << "FORMAT can be LATEX, BLOOKET, NOOPTIONS, or PLAINTEXT. Defaults to BLOOKET." << std::endl;
    return;
}

int main(int argc, char *argv[]){
    int exampleQuestions = 100;
    bool binary = true;
    bool vector = true;
    TextFormat format = BLOOKET;
    if(argc > 1){
        if(strncmp(argv[1], "--help", sizeof("--help")) == 0
                || strncmp(argv[1], "-h", sizeof("-h")) == 0){
            showHelp(argv[0]);
            return 0;
        }
        try{
            exampleQuestions = std::stoi(argv[1]);
            if(exampleQuestions <= 0){
                std::cerr << "Number of questions must be a positive integer." << std::endl;
                showHelp(argv[0]);
                return 1;
            }
            if(argc > 2){
                if(strncmp(argv[2], "LATEX", sizeof("LATEX")) == 0){
                    format = LATEX;
                } else if(strncmp(argv[2], "BLOOKET", sizeof("BLOOKET")) == 0){
                    format = BLOOKET;
                } else if(strncmp(argv[2], "NOOPTIONS", sizeof("NOOPTIONS")) == 0){
                    format = NOOPTIONS;
                } else if(strncmp(argv[2], "PLAINTEXT", sizeof("PLAINTEXT")) == 0){
                    format = PLAINTEXT;
                } else{
                    std::cerr << "Unknown format: " << argv[2] << std::endl;
                    showHelp(argv[0]);
                    return 3;
                }
            }
        } catch (const std::invalid_argument& ia){
            std::cerr << "Invalid number of questions: " << argv[1] << std::endl;
            showHelp(argv[0]);
            return 2;
        }
        exampleQuestions = std::stoi(argv[1]);
    }
    std::vector<std::string> questions;
    QuestionBase *generator;
    if (binary) {
        generator = &Bin2Dec::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &Dec2Bin::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &BinAddition::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &BinSubstraction::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &BinMultiplication::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &BinQuotient::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &BinRemainder::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
    }
    if (vector) {
        generator = &VectorPQ::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &VectorP2Q::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &VectorQ2P::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &VectorAddition::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &ScalarMultiplication::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &LinearCombination::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &VectorLength::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
        generator = &UnitVector::getInstance();
        questions = generator->generateQuestions(exampleQuestions, format);
        for (auto &&question : questions) {
            std::cout << question;
        }
    }
    return 0;
}