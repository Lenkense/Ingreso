#include "Question.hpp"
#include "TextFormat.hpp"

#define _EXAMPLEADDITION_IMPLEMENTATION_
#include "ExampleAddition.hpp"

#define _EXAMPLEMULTIPLICATION_IMPLEMENTATION_
#include "ExampleMultiplication.hpp"

#define _EXAMPLEQUOTIENT_IMPLEMENTATION_
#include "ExampleQuotient.hpp"

int main() {
    QuestionBase *example;
    TextFormat format = PLAINTEXT;
    int numberOfQuestions = 5;
    example = &ExampleAddition::getInstance();
    for(auto &&q : example->generateQuestions(numberOfQuestions, format)){
        std::cout << q;
    }
    example = &ExampleMultiplication::getInstance();
    for(auto &&q : example->generateQuestions(numberOfQuestions, format)){
        std::cout << q;
    }
    example = &ExampleQuotient::getInstance();
    for(auto &&q : example->generateQuestions(numberOfQuestions, format)){
        std::cout << q;
    }
    return 0;
}