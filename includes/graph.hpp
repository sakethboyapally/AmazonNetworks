#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include "../includes/utils.hpp"

using namespace std;

class Graph {
public:

    Graph(string filename);

    void DFS(int node);
    void fillOrder(int node);

    int Kosarajus();
    
    int Djistrka();

    void addEdge(int node, int edge);
    

    vector<vector<int>> getTranspose();
    vector<vector<int>>& getAdjacent();

private:
    size_t size;
    vector<vector<int>> adjacent;
    vector<bool> visited;
    stack<int> Stack;
    
    vector<int> order;
};
