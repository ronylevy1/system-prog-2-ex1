roniki04@gmail.com

In this task we were asked to create a class that represents a graph and apply algorithms to the graphs.

The assignment was divided into 2:

Graph:
    This part contains a class that represents a graph. The class contains the loadGraph and printGraph operations:

    loadGraph: This operation receives an adjacency matrix and loads it into the graph checks if the matrix is ​​positive and changes the values ​​of the variables accordingly.
    printGraph: This operation prints the representation of the graph, the number of vertices and the number of edges.

    In addition, I added 4 more functions, each of which provides important information about the graph:

    getGraph(): The function returns the adjacency matrix of the graph, thus allowing the user to perform additional operations on it.

    getWeighted(): The function returns true or false depending on whether the graph is weighted or not.

    getDirected(): The function returns true or false depending on whether the graph is directed or not.

    numVertices(): The function returns the number of vertices in the graph. This is essential for performing operations such as iterating over all nodes, or when it is necessary to know the size of the graph.


Algorithms:
    This part contains implementation for algorithms on graph.

    isConnected: checks if the graph is connected. It uses DFS to test the serviceability of the graph. If the graph is empty or there is only one tree in it, it returns "true", otherwise it checks if the number of nodes checked in the second DFS is equal to the number of nodes in the graph and if they are equal, then the graph is connected.

    shortestPath: Returns the shortest path between start and end nodes in the graph. If the graph is unweighted, it uses BFS to find the shortest path. Otherwise, it uses the Bellman-Ford algorithm.

    isContainsCycle: checks whether the graph contains cycles. It uses DFS to check if there are circles in the graph.

    negativeCycle: checks whether the graph contains a negative cycle. It uses the Bellman-Ford algorithm to check if there is a negative cycle in the graph

    isBipartite: checks whether the graph is a bipartite graph. It uses BFS to check whether the join of the graph can be divided into two groups such that arcs from one group do not start at a node from the other group.

    