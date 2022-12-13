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
    //parsing the file
    if (!input.is_open()) {
        cout << "File not found" << endl;
        return;
    }
    //going line by line and adding the edges
    string line;
    while (getline(input, line)) {
        if (line[0] == '#' || onlySpaces(line)) continue;
        istringstream str(line);
        pair<int,int> pair;
        str >> pair.first >> pair.second;
        n = max({n, pair.first, pair.second}); //get the max node
        addEdge(pair.first, pair.second);
    }
    //setting variables accordingly
    this->size = adjacent.size();
    this->visited.resize(n+1, false);
    this->nodes = n;
}


vector<int> Graph::DFS(int node) {
    vector<int> ans;
    size_t s = adjacent.size();
    stack.push(node);
    visited[node] = true;
    while (!stack.empty()) {
        int current = stack.top();
        cout << current << endl;
        ans.push_back(current);
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
    //resetting the visited vector for the next DFS
    kvisited = visited;
    this->visited.clear();
    this->visited.resize(this->nodes + 1, false);
    return ans;
}


bool Graph::Kosarajus() {
    //run DFS on the graph first pass
    DFS(0);
    for (size_t i = 0; i < visited.size(); i++) {
        if (!kvisited[i]) {
            cout << "Not a strongly connected graph" << endl;
            return false;
        }
    }
    //Doing a second pass on the transpose of the graph
    vector<vector<int>> transpose = getTranspose();
    this->adjacent = transpose;
    DFS(0);
    for (size_t i = 0; i < visited.size(); i++) {
        if (!kvisited[i]) {
            cout << "Not a strongly connected graph" << endl;
            return false;
        }
    }
    //If all nodes are visited, then it is a strongly connected graph
    cout << "Strongly connected graph" << endl;
    return true;
}








vector<vector<int>>& Graph::getAdjacent() {
    //getter for adjacency list
    return adjacent;
}





vector<int> Graph::Djistrka(int start, int end) {
    vector<int> dist(size, numeric_limits<int>::max());
    vector<int> prev(size, -1);
    vector<int> visit(size, false);
    dist[start] = 0;
    //creating priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (size_t i = 0; i < adjacent[u].size(); i++) {
            //checking distances of the potential node paths
            int v = adjacent[u][i];
            int weight = 1;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    //using previous vector to put the path into an answer vector
    vector<int> path;
    for (int i = end; i != -1; i = prev[i]) {
        path.push_back(i);
    }
    //reversing it to get the correct direction
    reverse(path.begin(), path.end());
    return path;
}


vector<vector<int>> Graph::getTranspose() {
    //Reverses the edges and nodes of the graph creating a transpose
    vector<vector<int>> transpose;
    transpose.resize(size, vector<int>());
    for (size_t i = 0; i < size; i++) {
        for (auto it : adjacent[i]) {
            transpose[it].push_back(i);
        }
    }
    return transpose;
}

















































