#pragma once
#include <iostream>
#include <vector>
namespace ariel {
class Graph {
   private:
    std::vector<std::vector<int>> mat;
    bool isDirected = false;    // Is not directed
    bool isWeigh = false;  // Is not weighted

   public:
    void loadGraph(std::vector<std::vector<int>>);
    void printGraph();
    std::vector<std::vector<int>> getGraph() const;
    bool getWeighted() const;
    bool getDirected() const;

    int numVertices() const;
};
};  // namespace ariel