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

    string trimLeft(const string &str);
    string trimRight(const string &str);


private:
    size_t size;
    vector<vector<int>> adjacent;
    vector<bool> visited;
    stack<int> Stack;

};
