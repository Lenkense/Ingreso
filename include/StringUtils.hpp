#include <string>
#include <vector>

#ifndef _STRINGUTILS_HPP_
#define _STRINGUTILS_HPP_

inline const static std::string sqrtSymbol = "\u221A";

inline std::string emptyVector(size_t n) {
    std::string result = "(";
    for(size_t i = 0; i < n; i++) {
        result += "%s";
        if(i < n - 1) result += ", ";
    }
    result += ")";
    return result;
}

inline std::string vectorToString(const std::vector<int>& vec) {
    std::string result = "(";
    for(size_t i = 0; i < vec.size(); i++) {
        result += std::to_string(vec[i]);
        if(i < vec.size() - 1) result += ", ";
    }
    result += ")";
    return result;
}

inline std::string sqrtToString(int value) {
    return sqrtSymbol + "(" + std::to_string(value) + ")";
}

std::string removeLeadingZeros(const std::string& s) {
    size_t pos = s.find_first_not_of('0');
    return (pos == std::string::npos) ? "0" : s.substr(pos);
}

#endif