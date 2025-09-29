#include <iostream>
#include "Question.hpp"
#include "Bin2Dec.hpp"
#include "Dec2Bin.hpp"
#include "Addition.hpp"
#include "Substraction.hpp"
#include "PQvector.hpp"
#include "VectorP2Q.hpp"

int main(int argc, char *argv[]){
    Question<Bin2Dec>& generator1 = Bin2Dec::getInstance();
    auto questions = generator1.generateQuestions(10);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<Dec2Bin>& generator2 = Dec2Bin::getInstance();
    questions = generator2.generateQuestions(10);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<Addition>& generator3 = Addition::getInstance();
    questions = generator3.generateQuestions(10);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<Substraction>& generator4 = Substraction::getInstance();
    questions = generator4.generateQuestions(10);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<PQvector>& generator5 = PQvector::getInstance();
    questions = generator5.generateQuestions(10);
    for (auto &&question : questions) {
        std::cout << question;
    }
    Question<VectorP2Q>& generator6 = VectorP2Q::getInstance();
    questions = generator6.generateQuestions(10);
    for (auto &&question : questions) {
        std::cout << question;
    }
    return 0;
}