#include "../includes/utils.hpp"

std::pair<int, int> splitLine(std::string& line) {
    std::string trim = trimLeft(trimRight(line));
    std::pair<int, int> ans;

    size_t index = trim.find_first_of(" ");
    ans.first = std::stoi(trim.substr(0, index));
    trim.erase(0, index);

    std::string second = trimLeft(trim);
    ans.second = std::stoi(second);
    return ans;
}

std::string trimLeft(const std::string &str) {
    std::string tmp = str;
    return tmp.erase(0, tmp.find_first_not_of(" "));
}

std::string trimRight(const std::string &str) {
    std::string tmp = str;
    return tmp.erase(tmp.find_last_not_of(" ") + 1);
}

bool onlySpaces(const std::string& str) {
   return str.find_first_not_of (' ') == str.npos;
}