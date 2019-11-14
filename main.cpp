#include "readfile.h"
#include "kempe.h"
#include <unordered_map>

int main() {
    std::vector<std::unordered_map<Node, float> > graph = readfile();

    int seed_size = 10;
    std::unordered_set<Node> maximized_set = greedy_maximize_influence(seed_size);
    return 0;
}