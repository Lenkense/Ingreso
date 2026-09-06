#include "Document.hpp"
#include "DocumentPlainText.hpp"

class DocumentNoOptions : DocumentPlainText{
public:
    DocumentNoOptions() {};
    ~DocumentNoOptions() {};
private:
    std::string insert_options(std::vector<std::string> options) override{
        return std::string();
    }
    virtual std::string insert_answer(Question question){
        return question.getTextAnswer();
    }
};
