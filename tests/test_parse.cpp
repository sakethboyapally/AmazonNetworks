#include "catch2/catch_test_macros.hpp"

#include "../includes/graph.hpp"

#include "../includes/utils.hpp"

using namespace std;

TEST_CASE("Parse Test Split Line") {
   string line = "2769                     18   ";
    pair<int, int> user = splitLine(line);
    pair<int, int> ans;
    ans.first = 2769;
    ans.second = 18;

    REQUIRE(user == ans);
}

TEST_CASE("Parse Test Split Line 2") {
    string line = "2769 20";
    pair<int, int> user = splitLine(line);
    pair<int, int> ans;
    ans.first = 2769;
    ans.second = 20;

    REQUIRE(user == ans);
}

TEST_CASE("Constructor Adjacency Matrix 1") {
    string file = "../data/test_file_simple_1.txt";
    Graph g(file);

    vector<vector<int>> expected = {
        {1, 2},
        {3, 5},
        {3},
        {},
        {},
        {3}
    };


    REQUIRE(expected == g.getAdjacent());
}

TEST_CASE("Constructor Adjacency Matrix 2") {
    string file = "../data/test_file_simple_2.txt";
    Graph g(file);

    vector<vector<int>> expected = {
        {2, 3},
        {4, 6},
        {3, 4, 0},
        {1},
        {5},
        {6, 1, 0},
        {5}
    };

    REQUIRE(expected == g.getAdjacent());
}

TEST_CASE("Constructor Adjacency Matrix 3") {
    string file = "../data/test_file_parsing_1.txt";
    Graph g(file);

    vector<vector<int>> expected = {
        {1, 2, 4},
        {2, 3, 4, 6},
        {0, 1},
        {},
        {},
        {},
        {3}
    };

    REQUIRE(expected == g.getAdjacent());
}

TEST_CASE("DFS Simple Test 1") {
    
}