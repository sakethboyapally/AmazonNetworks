#include <utility>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>

std::pair<int, int> splitLine(std::string& line);

std::string trimLeft(const std::string &str);
std::string trimRight(const std::string &str);