#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "helpers.h"
typedef int Node;
using namespace std;

vector readfile(){
	int node_num = 6005;
	ifstream file("dataset.csv");
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