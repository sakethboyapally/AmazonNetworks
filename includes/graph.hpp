#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class Graph {
public:
    struct Node {
        int ID;
        int ASIN;
        string group;
        int salesrank;
        vector<int> similar;
    }

    Graph(string filename);
    int DFS();
    int Kosarajus();
    
    int Djistrka();

    void addEdge(int node, int edge);
    pair<int, int> splitLine(string& line);


    void addEdge(int node, int edge);
    pair<int, int> splitLine(string& line);


private:

    vector<vector<int>> adjacent;


};
