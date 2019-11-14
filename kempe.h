#include <kempe.cpp>


std::unordered_set<Node>& greedy_maximize_influence(
    std::vector<std::unordered_map<Node, float> >& graph,
    std::unordered_set<Node>& empty_nodes,
    Node max_node,
    int size);