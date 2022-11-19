#pragma once

#include <vector>

#include <fstream>
#include <iostream>

#include <string>


using namespace std;


class Parser {
public:
    Parser(string filename);

    vector<string> splitFile(string file);
    vector<string> splitLine(string line);

private:
    string filename_;

};