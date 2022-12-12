
#include "../includes/graph.hpp"
#include "../includes/utils.hpp"
int main() {
    string file = "../test_file.txt";
    string file2 = "../data/Amazon0302.txt";
    Graph g(file);

    // vector<vector<int>> expected = {
    //     {1, 2},
    //     {3, 5},
    //     {3},
    //     {},
    //     {},
    //     {3}
    // };
    // vector<vector<int>> x = g.getAdjacent();
    // if (expected == x) {
    //     std::cout << "SUCCESS" <<std::endl;
    // } else {
    //     std::cout << "FAIL" << std::endl;
    // }
    cout << "DFS Traversal" << endl;
    g.DFS(0);
    cout << endl;
    cout << "Kosarajus Traversal" << endl;
    g.Kosarajus();
    cout << endl;
    cout << "Djisrka Traversal" << endl;
    vector<int> vec = g.Djistrka(0, 5);
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

}