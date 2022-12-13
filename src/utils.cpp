#include "../includes/utils.hpp"


bool onlySpaces(const std::string& str) {
   return str.find_first_not_of (' ') == str.npos;
}