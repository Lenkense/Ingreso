#include <iostream>
#include "Question.hpp"
#include "Bin2Dec.hpp"
#include "Dec2Bin.hpp"
#include "Addition.hpp"
#include "Substraction.hpp"
#include "PQvector.hpp"
#include "VectorP2Q.hpp"
#include "VectorQ2P.hpp"
#include "VectorAddition.hpp"

int main(int argc, char *argv[]){
    int exampleQuestions = 2;
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
    return 0;
}