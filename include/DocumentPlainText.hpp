#include <fstream>
#include <sstream>
#include "Document.hpp"

class DocumentPlainText : Document {
public:
    DocumentPlainText() {};
    ~DocumentPlainText() {};
    void create_output(
        std::string filename, std::vector<Question> questions){
            std::ofstream output(filename + extension);
            std::ofstream answers(filename + "_answers" + extension);
            output << "Questions:" << std::endl;
            answers << "Answers:" << std::endl;
            for (int i = 0; i < questions.size(); i++) {
                output << i + 1 << ") " << questions[i].getQuestion() << std::endl;
                auto options = questions[i].getOptions();
                output << insert_options(questions[i].getOptions());
                answers << i + 1 << ") " <<  insert_answer(questions[i]) << std::endl;
            }
            answers.close();
            output.close();
        }

private:
    const static inline std::string extension = ".txt";
    virtual std::string insert_options(std::vector<std::string> options){
        std::ostringstream output;
        for(int j = 0; j < options.size(); j++){
            output << "    " << std::string(1, 'a' + j) << ". " << options[j] << std::endl;
        }
        return output.str();
    }
    virtual std::string insert_answer(Question question){
        return std::string(1, 'a' + question.getNumberAnswer());
    }
};

