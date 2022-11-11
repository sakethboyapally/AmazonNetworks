#pragma once

#include "parse.hpp"
#include <vector>
#include <string>
using namespace std;

class Graph {
public:
    Graph(string file);
    int DFS();
    int BFS();
    int Djistrka();

private:
    vector<pair<int,int>> adjacent;
    

};
