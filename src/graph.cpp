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
    ifstream input(filename);
    input.open(filename);
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
   for (size_t i = 0; i < adjacent.size(); i++) {
    if (adjacent[node][i] == 1 && !visited[i]) {
        DFS(i);
    }
   }
   order.push_back(node);
}

void Graph::DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    
    for(vector<int>::iterator i = adjacent[node].begin(); i != adjacent[node].end(); ++i) {
        if(!visited[*i]) DFS(*i);
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


vector<vector<int>>& Graph::getAdjacent() {
    return adjacent;
}

void Graph::Kosarajus() {
    
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            fillOrder(i);
        }
    }

   
    Graph gr = getTranspose();
 
    
    for(int i = 0; i < size; i++) {
        visited[i] = false;
    }
 
    
    while (!Stack.empty()) {
        
        int v = Stack.top();
        Stack.pop();
 
        
        if (visited[v] == false) {
            gr.DFS(v);
        }
    }
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





