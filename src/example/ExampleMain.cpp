#include "Question.hpp"
#include "ExampleAddition.hpp"

#define _EXAMPLEADDITION_IMPLEMENTATION_

int main() {
    Question<ExampleAddition>& example = ExampleAddition::getInstance();
    for(auto &&q : example.generateQuestions(20)) {
        std::cout << q;
    }
    return 0;
}