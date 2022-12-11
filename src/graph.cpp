#include "../includes/graph.hpp"

void Graph::addEdge(int node, int edge) {
    if (node < 0) return;

    // if (adjacent.empty()) {
    //     if (node == 0) {
    //         vector<int> vec(1, edge);
    //         adjacent.push_back(vec);
    //     } else {
    //         return;
    //     }
    // }

    if ((size_t) node < adjacent.size()) {
        adjacent[node].push_back(edge);
    } else if ((size_t) node == adjacent.size()) {
        vector<int> vec(1, edge);
        adjacent.push_back(vec);
    } else {
        while (adjacent.size() != (size_t) node) {
            adjacent.push_back(vector<int>());
        }
        vector<int> vec(1, edge);
        adjacent.push_back(vec);
    }
}



Graph::Graph(string filename) {
    ifstream input;
    input.open(filename);
    if (!input.is_open()) {
        cout << "File not found" << endl;
        return;
    }
    string line;
    while (getline(input, line)) {
        if (line[0] == '#') continue;
        pair<int,int> pair = splitLine(line);
        
        addEdge(pair.first, pair.second);
    }

    this->size = adjacent.size();
    vector<bool> temp(size, false);
    this->visited = temp;
}


void Graph::DFS(int node) {
    visited[node] = true;
    for (size_t i = 0; i < adjacent[node].size(); i++) {
        if (!visited[adjacent[node][i]]) {
            DFS(adjacent[node][i]);
        }
    }
}







vector<vector<int>>& Graph::getAdjacent() {
    return adjacent;
}


vector<vector<int>> Graph::getTranspose() {
    vector<vector<int>> transpose(size, vector<int>(size, 0));
    for (size_t i = 0; i < adjacent.size(); i++) {
        for (size_t j = 0; j < adjacent[i].size(); j++) {
            transpose[j][i] = adjacent[i][j];
        }
    }
    return transpose;
}











































