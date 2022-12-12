#include "../includes/graph.hpp"

void Graph::addEdge(int node, int edge) {
    if (node < 0) return;

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
    int n = 0;
    ifstream input;
    input.open(filename);
    if (!input.is_open()) {
        cout << "File not found" << endl;
        return;
    }
    string line;
    while (getline(input, line)) {
        if (line[0] == '#' || onlySpaces(line)) continue;
        pair<int,int> pair = splitLine(line);
        n = max({n, pair.first, pair.second});
        addEdge(pair.first, pair.second);
    }

    this->size = adjacent.size();
    this->visited.resize(n+1, false);
    this->nodes = n;
}


void Graph::DFS(int node) {
    size_t s = adjacent.size();
    stack<int> stack;
    stack.push(node);
    visited[node] = true;
    while (!stack.empty()) {
        int current = stack.top();
        cout << current << endl;
        stack.pop();
        if ((size_t)current >= s) continue;
        for (size_t i = 0; i < adjacent[current].size(); i++) {
            int curr = adjacent[current][i];
            if (!visited[curr]) { //not visited
                stack.push(curr);
                visited[curr] = true;
            }
        }
    }

    this->visited.clear();
    this->visited.resize(this->nodes + 1, false);
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











































