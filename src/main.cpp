#include <iostream>
#include <cstring>
#include "Question.hpp"
#include "Bin2Dec.hpp"
#include "Dec2Bin.hpp"
#include "BinAddition.hpp"
#include "BinSubstraction.hpp"
#include "PQvector.hpp"
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
    Question<Bin2Dec>& generator1 = Bin2Dec::getInstance();
    auto questions = generator1.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<Dec2Bin>& generator2 = Dec2Bin::getInstance();
    questions = generator2.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<BinAddition>& generator3 = BinAddition::getInstance();
    questions = generator3.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<BinSubstraction>& generator4 = BinSubstraction::getInstance();
    questions = generator4.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<PQvector>& generator5 = PQvector::getInstance();
    questions = generator5.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<VectorP2Q>& generator6 = VectorP2Q::getInstance();
    questions = generator6.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<VectorQ2P>& generator7 = VectorQ2P::getInstance();
    questions = generator7.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<VectorAddition>& generator8 = VectorAddition::getInstance();
    questions = generator8.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<ScalarMultiplication>& generator9 = ScalarMultiplication::getInstance();
    questions = generator9.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<LinearCombination>& generator10 = LinearCombination::getInstance();
    questions = generator10.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<VectorLength>& generator11 = VectorLength::getInstance();
    questions = generator11.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<UnitVector>& generator12 = UnitVector::getInstance();
    questions = generator12.generateQuestions(exampleQuestions, format);
    for (auto &&question : questions) {
        std::cout << question;
    }
    return 0;
}