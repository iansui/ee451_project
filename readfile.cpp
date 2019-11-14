#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "helpers.h"
typedef int Node;
using namespace std;

vector<unordered_map<Node, float> >& readfile(){
	int node_num = 6005;
	ifstream file("dataset/dataset.csv");
	string line = "";
	
	vector<unordered_map<Node, float> > node_vec(node_num);
	if(file.fail()){
		cout<<"Error opening file"<<endl;
	}
	while(getline(file, line)){
		Edge edge = parse_edge(line);
		int source = edge.source;
		int target = edge.target;
		float weight = edge.weight;
		
		node_vec[source][target] = weight;
	}

	file.close();
	return node_vec;
}

int get_node_number() {
	return 6005;
}

std::unordered_set<Node>& get_empty_nodes() {
	return ;
}