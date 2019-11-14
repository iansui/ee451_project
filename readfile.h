#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

typedef int Node;

std::vector<std::unordered_map<Node, float> >& readfile();

std::unordered_set<Node>& get_empty_nodes();
