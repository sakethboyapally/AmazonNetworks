
#include "../includes/graph.hpp"
#include "../includes/utils.hpp"
int main() {
    string file = "../test_file.txt";
    Graph g(file);

    vector<vector<int>> expected = {
        {1, 2},
        {3, 5},
        {3},
        {},
        {},
        {3}
    };
    vector<vector<int>> x = g.getAdjacent();
    if (expected == x) {
        std::cout << "SUCCESS" <<std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    g.DFS(0);
}