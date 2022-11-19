#pragma once

#include <vector>
#include <string>
using namespace std;

class Graph {
public:

    Graph(string filename);
    int DFS();
    int Kosarajus();
    int Djistrka();

    void addEdge(int node, int edge);
    pair<int, int> splitLine(string& line);


private:

    vector<vector<int>> adjacent;
};
