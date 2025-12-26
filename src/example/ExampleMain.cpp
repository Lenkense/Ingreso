#include "Question.hpp"

#define _EXAMPLEADDITION_IMPLEMENTATION_
#include "ExampleAddition.hpp"

#define _EXAMPLEMULTIPLICATION_IMPLEMENTATION_
#include "ExampleMultiplication.hpp"

#define _EXAMPLEQUOTIENT_IMPLEMENTATION_
#include "ExampleQuotient.hpp"

int main() {
    QuestionBase *example;
    example = &ExampleAddition::getInstance();
    for(auto &&q : example->generateQuestions(20, PLAINTEXT)){
        std::cout << q;
    }
    example = &ExampleMultiplication::getInstance();
    for(auto &&q : example->generateQuestions(20, PLAINTEXT)){
        std::cout << q;
    }
    example = &ExampleQuotient::getInstance();
    for(auto &&q : example->generateQuestions(20, PLAINTEXT)){
        std::cout << q;
    }
    return 0;
}