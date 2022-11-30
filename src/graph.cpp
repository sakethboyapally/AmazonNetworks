#include "../includes/graph.hpp"
#include "../includes/utils.hpp"

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



Graph::Graph(string& filename) {
    ifstream input(filename);
    string line = "";
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
   // cout << node << " ";
 
    
    for (vector<int>::iterator i = adjacent[node].begin(); i != adjacent[node].end(); ++i) {
        if (!visited[*i]) DFS(*i);
    }
}

void Graph::fillOrder(int node ) {
    visited[node] = true;
    // cout << node << " ";

    // Recur for all the vertices adjacent to this vertex
    for(vector<int>::iterator i = adjacent[node].begin(); i != adjacent[node].end(); ++i) {
        if(!visited[*i]) fillOrder(*i);
    }
 
    // All vertices reachable from v are processed by now, push v
    Stack.push(node);
}


