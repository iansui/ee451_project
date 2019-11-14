#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "readfile.cpp"
typedef int Node;

std::vector<std::unordered_map<Node, float> >& readfile();

int get_node_number();

std::unordered_set<Node>& get_empty_nodes();