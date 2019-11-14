#include "readfile.h"
#include "kempe.h"
#include <unordered_map>

int main() {
    std::vector<std::unordered_map<Node, float> >& graph = readfile();
    int max_node = 1;//NODE_NUM;
    std::unordered_set<Node>& empty_nodes = get_empty_nodes();
    int seed_size = 10;

    std::unordered_set<Node> maximized_set = greedy_maximize_influence(graph, empty_nodes, max_node, seed_size);
    return 0;
}