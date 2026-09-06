#include <iostream>
#include <string>
#include <fstream>
#include "Document.hpp"

class DocumentBlooket : Document{
public:
    DocumentBlooket() {}
    ~DocumentBlooket() {}
    void create_output(
        std::string filename, std::vector<Question> questions){
            std::ofstream output(filename + extension);
            output << header;
            for(int i = 0; i < questions.size(); i++){
                int numOfOptions = questions[i].getOptions().size();
                output << i + 1 << ",";
                output << questions[i].getQuestion() << ",";
                for(auto &option : questions[i].getOptions()){
                    output << option << ",";
                }
                output << "300,";
                output << questions[i].getNumberAnswer() + 1 <<"\n";
            }
            output.close();
        }

private:
    const static inline std::string extension = ".csv";
    const static inline std::string header = 
    std::string("\"Blooket\nImport Template\",,,,,,,\n") +
    "Question #,Question Text,Answer 1,Answer 2,\"Answer 3\n" +
    "(Optional)\",\"Answer 4\n" +
    "(Optional)\",\"Time Limit (sec)\n" +
    "(Max: 300 seconds)\",\"Correct Answer(s)\n" +
    "(Only include Answer #)\"\n";
    const static inline int MAX_NUMBER_OF_OPTIONS = 4;
};