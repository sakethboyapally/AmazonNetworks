#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;

class Graph {
public:

    Graph(string& filename);

    void DFS(int node);
    void fillOrder(int node);

    int Kosarajus();
    
    int Djistrka();

    void addEdge(int node, int edge);
    pair<int, int> splitLine(string& line);


    void addEdge(int node, int edge);
    pair<int, int> splitLine(string& line);


private:
    size_t size;
    vector<vector<int>> adjacent;
    vector<bool> visited (size, false);
    stack<int> Stack;

};
