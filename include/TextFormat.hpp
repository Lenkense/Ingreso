#ifndef _TEXTFORMAT_HPP_
#define _TEXTFORMAT_HPP_

enum TextFormat: u_int8_t{
    LATEX,
    BLOOKET,
    NOOPTIONS,
    PLAINTEXT,
    LATEXNOOPTIONS
};

inline std::string formatExtension(TextFormat textFormat){
    switch (textFormat){
        case LATEX:
        case LATEXNOOPTIONS:
            return ".tex";
        case BLOOKET:
            return ".csv";
        case NOOPTIONS:
        case PLAINTEXT:
            return ".txt";
        default:
            std::cerr << "Unknown format!" << std::endl;
            exit(1);
    }
};

#endif
