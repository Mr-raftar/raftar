#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Graph {
public:
    int V; // Number of vertices (landmarks)
    vector<vector<pair<int, int>>> adjList; // Adjacency list to store the graph

    Graph(int V); // Constructor to initialize graph
    void addEdge(int u, int v, int weight); // Method to add edge to graph
    void dijkstra(int source); // Dijkstra's algorithm to find shortest paths
};

// Constructor to initialize the graph
Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

// Method to add an edge to the graph
void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight)); // Since the graph is undirected
}

// Dijkstra's algorithm to find the shortest paths from a source node
void Graph::dijkstra(int source) {
    // Create a priority queue to store vertices that are being processed
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to store shortest distance from source to each vertex
    vector<int> dist(V, INT_MAX);
    dist[source] = 0; // Distance from source to itself is 0

    pq.push(make_pair(0, source)); // Push the source with distance 0

    // Process the vertices in the priority queue
    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest distance
        pq.pop();

        // Process all the neighbors of u
        for (auto &neighbor : adjList[u]) {
            int v = neighbor.first; // Neighbor vertex
            int weight = neighbor.second; // Edge weight

            // If a shorter path to v is found, update the distance
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v)); // Push the neighbor with updated distance
            }
        }
    }

    // Print the shortest distance from source to all vertices
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "To landmark " << i << ": INF (no path)\n";
        } else {
            cout << "To landmark " << i << ": " << dist[i] << " units\n";
        }
    }
}

int main() {
    // Number of landmarks (nodes)
    int V = 5; // A, B, C, D, E
    Graph g(V);

    // Add edges (landmark distances)
    g.addEdge(0, 1, 4); // A -> B (4 units)
    g.addEdge(0, 2, 1); // A -> C (1 unit)
    g.addEdge(1, 2, 2); // B -> C (2 units)
    g.addEdge(1, 3, 5); // B -> D (5 units)
    g.addEdge(2, 3, 8); // C -> D (8 units)
    g.addEdge(2, 4, 10); // C -> E (10 units)
    g.addEdge(3, 4, 2); // D -> E (2 units)

    // Run Dijkstra's algorithm starting from landmark A (node 0)
    g.dijkstra(0);

    return 0;
}
