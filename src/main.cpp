
#include "../includes/graph.hpp"
#include "../includes/utils.hpp"
int main() {
    string file = "../data/test_file.txt";
    string file2 = "../data/Amazon0302.txt";
    string file3 = "../test_file2.txt";
    Graph g(file);

   
    cout << "DFS Traversal" << endl;
    g.DFS(0);
    cout << endl;
    cout << "Kosarajus Traversal" << endl;
    g.Kosarajus();
    cout << endl;
    cout << "Djistrka Traversal" << endl;
    cout << "PATH from 0 to 5: ";
    vector<int> vec = g.Djistrka(0, 5);
    for (size_t i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) {
            cout << vec[i] << endl;
            break;
        }
        cout << vec[i] << "->" << " ";
    }
    cout << endl;

}