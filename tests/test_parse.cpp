#include "catch2/catch_test_macros.hpp"

#include "../includes/graph.hpp"

#include "../includes/utils.hpp"

using namespace std;



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
    string file = "../data/test_file_simple_1.txt";
    Graph g(file);
    vector<int> vec = g.DFS(0);
    vector<int> expected = {0, 2, 3, 1, 5};
    REQUIRE(vec == expected);
}

TEST_CASE("DFS Simple Test 2") {
   string file = "../data/test_file_simple_2.txt";
    Graph g(file);
    vector<int> vec = g.DFS(0);
    vector<int> expected = {0, 3, 1, 6, 5, 4, 2};
    REQUIRE(vec == expected);
}



TEST_CASE("Kosarajus Test") {
    string file = "../data/test_weakly.txt";
    Graph g(file);
    REQUIRE(g.Kosarajus() == true);
}



TEST_CASE("Dijkstras Test 1") {
    string file = "../data/test_file.txt";
    Graph g(file);
    vector<int> path = g.Djistrka(0, 5);
    vector<int> expected = {0, 1, 2, 3, 4, 5};
    REQUIRE(path == expected);
}

TEST_CASE("Dijkstras Test 2") {
    string file = "../data/test_file.txt";
    Graph g(file);
    vector<int> path = g.Djistrka(0, 3);
    vector<int> expected = {0, 1, 2, 3};
    REQUIRE(path == expected);
}

TEST_CASE("Dijkstras Test 3") {
    string file = "../data/test_file_simple_1.txt";
    Graph g(file);
    vector<int> path = g.Djistrka(0, 5);
    vector<int> expected = {0, 1, 5};
    REQUIRE(path == expected);
}