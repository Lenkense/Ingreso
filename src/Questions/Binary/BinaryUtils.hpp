#include <string>
#include <vector>

#ifndef _BINARYUTILS_HPP_
#define _BINARYUTILS_HPP_

inline std::string removeLeadingZeros(const std::string& s) {
    size_t pos = s.find_first_not_of('0');
    return (pos == std::string::npos) ? "0" : s.substr(pos);
}

#endif