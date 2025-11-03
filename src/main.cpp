#include <iostream>
#include <cstring>
#include "Question.hpp"
#include "Bin2Dec.hpp"
#include "Dec2Bin.hpp"
#include "Addition.hpp"
#include "Substraction.hpp"
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
    std::cout << "Usage: " << programName << " [number_of_questions]" << std::endl;
    std::cout << "If number_of_questions is not provided, defaults to 100." << std::endl;
    return;
}

int main(int argc, char *argv[]){
    int exampleQuestions = 100;
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
        } catch (const std::invalid_argument& ia){
            std::cerr << "Invalid number of questions: " << argv[1] << std::endl;
            showHelp(argv[0]);
            return 2;
        }
        exampleQuestions = std::stoi(argv[1]);
    }
    Question<Bin2Dec>& generator1 = Bin2Dec::getInstance();
    auto questions = generator1.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<Dec2Bin>& generator2 = Dec2Bin::getInstance();
    questions = generator2.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<Addition>& generator3 = Addition::getInstance();
    questions = generator3.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<Substraction>& generator4 = Substraction::getInstance();
    questions = generator4.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<PQvector>& generator5 = PQvector::getInstance();
    questions = generator5.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<VectorP2Q>& generator6 = VectorP2Q::getInstance();
    questions = generator6.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<VectorQ2P>& generator7 = VectorQ2P::getInstance();
    questions = generator7.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<VectorAddition>& generator8 = VectorAddition::getInstance();
    questions = generator8.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<ScalarMultiplication>& generator9 = ScalarMultiplication::getInstance();
    questions = generator9.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<LinearCombination>& generator10 = LinearCombination::getInstance();
    questions = generator10.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<VectorLength>& generator11 = VectorLength::getInstance();
    questions = generator11.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<UnitVector>& generator12 = UnitVector::getInstance();
    questions = generator12.generateQuestions(exampleQuestions);
    for (auto &&question : questions) {
        std::cout << question;
    }
    return 0;
}