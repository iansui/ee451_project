#include "readfile.h"
#include "kempe.h"
#include <unordered_map>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {

    int thread_num, rank;
    MPI_Init(&argc,&argv);
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD,&thread_num);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    std::vector<std::unordered_map<Node, float> >& graph = readfile();
    int max_node = NODE_NUM;
    std::unordered_set<Node>& empty_nodes = get_empty_nodes();
    int seed_size = 10;
    int sample_times = 1;

	while(seed.size()<seed_size){
		Node node_with_max_influence; 
		std::unordered_set<Node> seed;
		if(rank == 0){

			for(int i=1;i<thread_num;i++){
				//send seed
				//send candidate
			}
			//*********loop
			//if receive any influence from slave, send another candidate
			//compare with node_with_max_influence and update
			//*************
			seed.insert(node_with_max_influence);

		}
		else{
			//**********************************should be in a loop
			
			//receive seed
			Node candidate;
			//receive candidate
			seed.insert(candidate);

			float influence = sample(graph, seed, sample_times);
			//send back influence
			//**********************************

		}
	}    
    std::unordered_set<Node> maximized_set = greedy_maximize_influence(graph, empty_nodes, max_node, seed_size);
    return 0;
}
