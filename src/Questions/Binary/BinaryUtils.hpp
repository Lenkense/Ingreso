#include <string>
#include <vector>

#ifndef _BINARYUTILS_HPP_
#define _BINARYUTILS_HPP_

inline constexpr size_t const_log2(size_t n) {
    return (n <= 1) ? 1 : 1 + const_log2(n/2);
}

inline std::string removeLeadingZeros(const std::string& s) {
    size_t pos = s.find_first_not_of('0');
    return (pos == std::string::npos) ? "0" : s.substr(pos);
}

#endif