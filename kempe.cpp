
#include <unordered_set>
typedef int Node;

int infect(std::unordered_set<Node>& seed) {
    return ;
}

float sample(std::unordered_set<Node>& seed, int times) {
    // Simulate
    int influence = 0;
    for(int iterate_time = 0; iterate_time < times; iterate_time++) {
        influence += infect(seed);
    }


    // return the number of active nodes
    return ((float)influence) / times;
}

/**
 * 
 */
Node select_maximize_node(std::unordered_set<Node>& seed, std::unordered_set<Node>& empty_nodes, Node max_node) {

    int sample_times = 0; // To be determined

    float max_influence = 0;
    Node maximized_node = -1;
    // for each node not in the seed set nor in the empty set
    for(Node candidate = 0; candidate <= max_node; candidate++) {
        if(empty_nodes.find(candidate) == empty_nodes.end && seed.find(candidate) == seed.end) {
            seed.insert(candidate);
            // Simulate activation for multiple times
            float influence = sample(seed, sample_times);
            // Update if influcence is larger
            if(influence > max_influence) {
                max_influence = influence;
                maximized_node = candidate;
            }
            else if(influence == max_influence) {
                // Arbitrary tie break

            }
            seed.erase(candidate);
        }
        
    }
    // Return the node with maximized influence
    return maximized_node;
}

std::unordered_set<Node>& greedy_maximize_influence(int size) {
    std::unordered_set<Node> seed;
    while(seed.size < size) {
        Node node_with_max_influence = select_maximize_node(seed, empty_nodes, max_node);
        seed.insert(node_with_max_influence);
    }
    return seed;
}