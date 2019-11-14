#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

typedef int Node;


const int NODE_NUM = 15; // 15, 13
const std::string FILE_NAME = "dataset/testset1.csv"; 
// Test1: testset1.csv
// Test2: testset2.csv

std::vector<std::unordered_map<Node, float> >& readfile();

std::unordered_set<Node>& get_empty_nodes();
