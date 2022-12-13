## StanfordLargeNetwork
Project on Analyzing Amazon Customer data using Graph Algorithms in C++

### Github Organization
All of our test cases are located within the "tests" folder of our repository. The test files we used as well as the actual Amazon data set is located within the "data" folder. Our graph algorithms and parsing code is located within "src". The graph algorithms can be found in "graph.cpp" and our code for parsing the source file can be found in "utils.cpp". The written report is labeled as "results.md" and the presentation video is labeled as "cs225final".

### Running Instructions
First, the user must open the directory in the cs225 docker container. The dockerfile is provided in the repository, but the individual user must download the docker desktop application on their own. See here: https://www.docker.com/products/docker-desktop/ 

In order to run the test cases we have written, we use the same general process as MP testing in CS 225. In your project directory using the terminal, input as follows.  1.)mkdir build 2.)cd build  3.)cmake .. 3.)make test 4.) ./test Steps 1 and 3 only need  to be completed the first time that the code is opened on a new machine . 



###

We can also do make and ./main to see the output from main. In the main file, for the DFS function you initialize a graph using the filename of your desired file as the parameter to the graph constructor, and then you can call the DFS on it.
###
For example:
###
Graph g("../test_file.txt");
###
Call DFS using the desired starting int node of the traversal
###
g.DFS(0);
###
The order of which the nodes are visited is written to standard output.
###
Call Djisktras using the desired starting int node and desired ending int node to find the shortest path.
###
vector<int> path = g.Djisktras(0, 5); 

The resulting vector is the path of nodes taken to travel from node 0 to node 5. This can be looped through and printed to standard output to view the contents of the vector.
  
  
  

Call Kosarajus Algorithm to see if the graph is strongly or weakly connected.
  
  
  
g.Kosarajus();
  


A statement "This is a strongly connected graph" or "This is a weakly connected graph" is written to standard output.
  
The test cases we wrote test the data parsing, the creation of an adjacency list from the raw Amazon data, as well as the output of our two algorithms, Djikstra's and Kosaraju's, when ran on the aforementioned adjacency list.

  
  
  
  Link to Final Presentation:
 https://drive.google.com/file/d/17JoMB_W8_0k8JN3AFj5iDo4ucXaG8vB3/view?usp=sharing
