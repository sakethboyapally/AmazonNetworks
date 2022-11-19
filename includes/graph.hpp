#pragma once

#include <vector>
#include <string>
using namespace std;

class Graph {
public:
    Graph(string filename);
    int DFS();
    
    int Djistrka();
    int Kosarajus();

private:
    vector<pair<int,vector<int>>> adjacent;
    

};
