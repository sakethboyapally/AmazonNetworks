#include "../includes/graph.hpp"
using namespace std;
#include <fstream>
#include <iostream>

Graph::Graph(string filename) {
    ifstream input(filename);
    string line = "";
    while (getline(input, line)) {
        if (line[0] == '#') continue;
        
        pair<int,int> pair = splitLine(line);
        addEdge(pair.first, pair.second);
        
    }
}

