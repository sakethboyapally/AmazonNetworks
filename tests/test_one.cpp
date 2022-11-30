#include <catch2/catch_test_macros.hpp>

#include "../includes/graph.hpp"

using namespace std;

TEST_CASE("Split Line Test") {
    const line = "similar: 5  0804215715  156101074X  0687023955  0687074231  082721619X";
    pair<int, int> user = splitLine(line);
}