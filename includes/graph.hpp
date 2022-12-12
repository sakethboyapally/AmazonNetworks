#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <limits>
#include <queue>
#include "../includes/utils.hpp"

using namespace std;

class Graph {
public:

    Graph(string filename);

    void DFS(int node);

    void Kosarajus();
    
    vector<int> Djistrka(int start, int end);

    void addEdge(int node, int edge);
    

    vector<vector<int>> getTranspose();
    vector<vector<int>>& getAdjacent();

private:
    size_t size;
    vector<vector<int>> adjacent;
    vector<bool> visited;
    int nodes;
    stack<int> Stack;
    
    vector<int> order;
};
