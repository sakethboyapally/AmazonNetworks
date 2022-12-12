# Results
## Output and Correctness of Each Algorithm
### DFS Output
The DFS traversal works as expected and gives us the nodes in the correct order. We know this as we created a test graph which we knew the correct traveral for and ran our DFS on it, which resulted in the correct output.

### Dijkstra's Algorithm Output
We wrote Dijkstra's algorithm in order to find the shortest path from a certain starting node to a certain ending node. Dijkstra's algorithm outputs a vector of ints which represent the nodes that are passed through on the shortest path from the start to end node. We were able to test this algorithm's functionality by creating a test graph whose shortest path from one node to another was known and checking whether the observed output vector was the same as the expected vector.

### Kosaraju's Algorithm Output
We wrote Kosarajus's algorithm to print whether or not the graph we inputed is strongly connected or weakly connected. Using different test graphs, we were able to see that it does in fact work as intended for this purpose.

## Leading Question and Answer
Our leading question was whether we would be able to find out if an Amazon customer would buy a certain product in the future given that they purchased a certain other product in the past. This question is harder than we thought to answer as while we were able to find closely related users through the products they had bought in the past, it's hard to say definitively if they'll follow the same purchasing habits as that other user.
