#include "catch2/catch_test_macros.hpp"

#include "../includes/graph.hpp"
// #include "../tests/test_file.txt"

using namespace std;

TEST_CASE("Parse Test Split Line") {
    Graph g("test_file.txt");
    
    string line = "19   5";
    pair<int, int> user = splitLine(line);
    pair<int, int> ans;
    ans.first = 19;
    ans.second = 5;

    REQUIRE(user == ans);
}

TEST_CASE("Parse Test Split Line 2") {
    string line = "  2769   20   ";
    pair<int, int> user = splitLine(line);
    pair<int, int> ans;
    ans.first = 2769;
    ans.second = 20;

    REQUIRE(user == ans);
}

// TEST_CASE("Parse Test Large File") {
//     string file = 'test_file.txt';


// }