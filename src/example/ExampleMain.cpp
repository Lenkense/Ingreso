#include "Question.hpp"

#define _EXAMPLEADDITION_IMPLEMENTATION_
#include "ExampleAddition.hpp"

int main() {
    Question<ExampleAddition>& example = ExampleAddition::getInstance();
    for(auto &&q : example.generateQuestions(20)) {
        std::cout << q;
    }
    return 0;
}