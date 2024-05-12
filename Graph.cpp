#include "Graph.hpp"
using namespace ariel;

using std::vector;

void Graph::loadGraph(vector<vector<int>> temp_graph) {
    this->mat = temp_graph;
    int size = temp_graph.size();

    for(size_t i = 0; i < size ; i++){
        if(temp_graph[i].size() != size){
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix");
        }
    }
    
    this->isWeigh = false;
    this->isDirected = false;
    for (size_t i = 0; i < size; i++) {  // Go all over the original graph and put there the values of the temp graph
        for (size_t j = 0; j < size; j++) {
            // If the graph is not weighted we will weighted it by 1
            if (mat[i][j] != 0 && mat[i][j] != 1) {
                this->isWeigh = true;  // If any edge has a weight other than 0 or 1, it's weighted
            }

            if (mat[i][j] != mat[j][i]) {
                this->isDirected = true;
            }
        }
    }
}

void Graph::printGraph() {
    int size = this->mat.size();

    int num_of_edges = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mat[i][j] != 0) {  // Its means that there ia an edge.
                num_of_edges++;
            }
        }
    }

    if (!this->isDirected) {
        //num_of_edges = 2*2;
    }

    std::cout << "Graph with " << size << " vertices and " << num_of_edges << " edges." << std::endl;
}

vector<vector<int>> Graph::getGraph() const {
    return this->mat;
}

bool Graph::getWeighted() const {
    return this->isWeigh;
}

bool Graph::getDirected() const {
    return this->isDirected;
}

int Graph::numVertices() const {
    return mat.size(); // Assuming the size of mat represents the number of vertices
}



