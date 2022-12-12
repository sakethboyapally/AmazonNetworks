
#include "../includes/graph.hpp"
#include "../includes/utils.hpp"
int main() {
    string file = "../test_file.txt";
    Graph g(file);

    vector<vector<int>> expected = {
        {4, 5},
        {0, 2, 4, 5},
        {0, 11, 13},
        {63, 64},
    };
    if (expected == g.getAdjacent()) {
        std::cout << "SUCCESS" <<std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    g.DFS(0);
    
    
}