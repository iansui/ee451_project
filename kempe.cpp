
#include <unordered_set>
#include <queue>
#include <unordered_map>

typedef int Node;

// Return a random number in [0, 1]
int getRamdomNumber() {
    return 1;
}

int infect(std::unordered_set<Node>& seed) {
    
    std::unordered_set<Node> infected = seed;
    std::vector<std::unordered_map<Node, float> > graph;

    std::queue<Node> infecting_nodes;

    for(auto it = infected.begin(); it != infected.end(); ++it) {
        infecting_nodes.push(*it);
    }

    while(!infecting_nodes.empty()) {
        Node current_infecting_node = infecting_nodes.front();
        infecting_nodes.pop();
        std::unordered_map<Node, float>& edges = graph[current_infecting_node];
        for(auto it = edges.begin(); it != edges.end(); ++it) {
            // The head of the edge is not infected and activation succeeds
            if(infected.find(it->first) == infected.end() && getRamdomNumber() > it->second) {
                infected.insert(it->first);
                infecting_nodes.push(it->first);
            }
        }
    }

    return infected.size();
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
Node select_maximize_node(std::unordered_set<Node>& seed, std::unordered_set<Node>& empty_nodes, Node min_node, Node max_node) {

    int sample_times = 100; // To be determined

    float max_influence = 0;
    Node maximized_node = -1;
    // for each node not in the seed set nor in the empty set
    for(Node candidate = min_node; candidate <= max_node; candidate++) {
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
                if(getRamdomNumber() > 0.5) {
                    max_influence = influence;
                    maximized_node = candidate;
                }
            }
            seed.erase(candidate);
        }
        
    }
    // Return the node with maximized influence
    return maximized_node;
}

std::unordered_set<Node>& greedy_maximize_influence(
    std::vector<std::unordered_map<Node, float> >& graph,
    std::unordered_set<Node>& empty_nodes,
    Node max_node,
    int size) {
    Node min_node = 1;
    std::unordered_set<Node> seed;
    while(seed.size() < size) {
        Node node_with_max_influence = select_maximize_node(seed, empty_nodes, min_node, max_node);
        seed.insert(node_with_max_influence);
    }
    return seed;
}

