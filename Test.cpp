#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    ariel::Graph g1;
    vector<vector<int>> connectedGraph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(connectedGraph);
    CHECK(ariel::Algorithms::isConnected(g1) == true);

    ariel::Graph g2;
    vector<vector<int>> disconnectedGraph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g2.loadGraph(disconnectedGraph);
    CHECK(ariel::Algorithms::isConnected(g2) == false);
}
TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g1, 0, 2) == "0->2");

    ariel::Graph g2;
    vector<vector<int>> graph20 = {
        {0, 0, 1},
        {0, 0, 0},
        {1, 0, 0}};
    g2.loadGraph(graph20);
    CHECK(ariel::Algorithms::shortestPath(g2, 0, 1) == "-1");
}


TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    ariel::Graph g1;
    vector<vector<int>> acyclicGraph = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g1.loadGraph(acyclicGraph);
    CHECK(ariel::Algorithms::isContainsCycle(g1) == false);

    ariel::Graph g2;
    vector<vector<int>> cyclicGraph = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g2.loadGraph(cyclicGraph);
    CHECK(ariel::Algorithms::isContainsCycle(g2) == true);
}


TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "1");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    ariel::Graph g1;
    vector<vector<int>> bipartiteGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(bipartiteGraph);
    CHECK(ariel::Algorithms::isBipartite(g1) == "1");

    ariel::Graph g2;
    vector<vector<int>> nonBipartiteGraph = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}};
    g2.loadGraph(nonBipartiteGraph);
    CHECK(ariel::Algorithms::isBipartite(g2) == "1");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test invalid graph size")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0},
        {0, 0, 4}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test invalid weighted graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {1, 0, 3},
        {2, 3, 0}};
    CHECK_THROWS(g.loadGraph(graph));
}











