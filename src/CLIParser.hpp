#include <string>
#include <vector>
#include "Singleton.hpp"
#include "TextFormat.hpp"

class CLIParser : Singleton<CLIParser> {
    friend class Singleton<CLIParser>;
public:
    using Singleton<CLIParser>::getInstance;
    void parse(int argc, char* argv[]){
        programName = argv[0];
        for (size_t i = 1; i < argc; i++) {
            std::string arg = argv[i];
            if (arg == "--help" || arg == "-h") {
                showHelp();
                exit(0);
            }
            if (arg == options[0] && i + 1 < argc) {
                numberOfQuestions = std::stoi(argv[++i]);
            } else if (arg == options[1] && i + 1 < argc) {
                textFormat = toTextFormat(argv[++i]);
            } else if (arg == options[2]) {
                binaryEnabled = false;
            } else if (arg == options[3]) {
                vectorEnabled = false;
            } else if (arg == options[4] && i + 1 < argc) {
                outputFile = argv[++i];
            } else {
                std::cerr << "Unknown option: " << arg << std::endl;
                showHelp();
                exit(1);
            }
        }
    };

    TextFormat toTextFormat(const std::string format) const
    {
        if (format == "LATEX") {
            return LATEX;
        } else if (format == "BLOOKET") {
            return BLOOKET;
        } else if (format == "NOOPTIONS") {
            return NOOPTIONS;
        } else if (format == "PLAINTEXT") {
            return PLAINTEXT;
        } else if (format == "LATEXNOOPTIONS") {
            return LATEXNOOPTIONS;
        } else {
            std::cerr << "Unknown format: " << format << std::endl;
            showHelp();
            exit(1);
        }
    };

    void showHelp() const
    {
        std::cout << "Generates a set of example questions for various question types." << std::endl;
        std::cout << "Usage: " << programName << " [options]" << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "  " << "-h | --help" << ": Show this help message" << std::endl;
        for (size_t i = 0; i < options.size(); i++) {
            std::cout << "  " << options[i] << ": " << descriptions[i] << std::endl;
        }
    };

    std::string getProgramName() const{ return programName; };
    int getNumberOfQuestions() const{ return numberOfQuestions; };
    TextFormat getTextFormat() const{ return textFormat; };
    bool isBinaryEnabled() const{ return binaryEnabled; };
    bool isVectorEnabled() const{ return vectorEnabled; };
    std::string getOutputFile() const{ return outputFile; };
private:
    friend class Singleton<CLIParser>;
    std::vector<std::string> options = {
        "-n",
        "-f",
        "--disable-binary",
        "--disable-vector",
        "-o"
    };
    std::vector<std::string> descriptions = {
        "Number of questions to generate (default: 5)",
        "Output format: LATEX, LATEXNOOPTIONS, BLOOKET, NOOPTIONS, PLAINTEXT (default: BLOOKET)",
        "Disable binary question types",
        "Disable vector question types",
        "Output file prefix (default: standard output)"
    };
    int numberOfQuestions = 5;
    TextFormat textFormat = BLOOKET;
    bool binaryEnabled = true;
    bool vectorEnabled = true;
    std::string outputFile = "";
    std::string programName = "";
};
