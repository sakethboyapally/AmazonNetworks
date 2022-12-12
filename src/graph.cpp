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
        
        pair<int,int> pair = splitLine(line);
        
        addEdge(pair.first, pair.second);
    }

    this->size = adjacent.size();
    
    this->visited.resize(size, false);
}


void Graph::DFS(int node) {
    stack<int> stack;
    stack.push(node);
    visited[node] = true;
    while (!stack.empty()) {
        int current = stack.top();
        cout << current << endl;
        stack.pop();
        for (size_t i = 0; i < adjacent[current].size(); i++) {
            if (!visited[adjacent[current][i]]) {
                stack.push(adjacent[current][i]);
                visited[adjacent[current][i]] = true;
            }
        }
    }
}


void Graph::Kosarajus() {
    DFS(0);
    for (size_t i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            cout << "Not a strongly connected graph" << endl;
            return;
        }
    }
    vector<vector<int>> transpose = getTranspose();
    visited = vector<bool>(size, false);
    DFS(0);
    for (size_t i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            cout << "Not a strongly connected graph" << endl;
            return;
        }
    }
    cout << "Strongly connected graph" << endl;
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











































