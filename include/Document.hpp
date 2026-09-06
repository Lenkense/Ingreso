#include <string>
#include <vector>
#include "Question.hpp"

class Document {
public:
    virtual void create_output(
        std::string filename, std::vector<Question> questions) = 0;

private:
    const static inline std::string extension = 0;
};