# Results
## Output and Correctness of Each Algorithm
### DFS Output
The DFS traversal works as expected and gives us the nodes in the correct order. We know this as we created a test graph which we knew the correct traveral for and ran our DFS on it, which resulted in the correct output.

### Dijkstra's Algorithm Output
We wrote Dijkstra's algorithm in order to find the shortest path from a certain starting node to a certain ending node. Dijkstra's algorithm outputs a vector of ints which represent the nodes that are passed through on the shortest path from the start to end node. We were able to test this algorithm's functionality by creating a test graph whose shortest path from one node to another was known and checking whether the observed output vector was the same as the expected vector.

### Kosaraju's Algorithm Output
We wrote Kosarajus's algorithm to print whether or not the graph we inputed is strongly connected or weakly connected. Using different test graphs, we were able to see that it does in fact work as intended for this purpose.

## Leading Question and Answer
Our leading question was whether we would be able to find out if an Amazon customer would buy a certain product in the future given that they purchased a certain other product in the past. The data we used was a directed graph where each node represented a product and an edge between two nodes showed that they were copurchased. Using Dijkstra's algorithm, we could view the shortest path between one node and another which we could then use to see how likely it was that one product be copurchased with another. For example, if there's relatively short path between two nodes, then it is likely that they will both be purchased by the same user even if there is no edge between the two nodes. Beyond that, if the nodes are strongly connected in accordance with Kosaraju's algorithm, we can say with even more certainty that those two products are likely to be copurchased. 
