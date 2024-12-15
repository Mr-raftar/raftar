#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>

using namespace std;

#define INF INT_MAX
#define V 6 // Number of vertices (departments)

// Adjacency List representation of the graph
class Graph {
public:
    list<pair<int, int>> *adjList; // Adjacency list
    int numVertices;

    Graph(int vertices); // Constructor
    void addEdge(int u, int v, int weight);
    void kruskalMST(); // Kruskal's algorithm
    void primMST(); // Prim's algorithm
};

// Constructor
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjList = new list<pair<int, int>>[vertices];
}

// Add edge to the adjacency list
void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight));
}

// Helper structure for Kruskal's algorithm
struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& e) {
        return weight < e.weight;
    }
};

// Find the set of an element (for Union-Find)
int findSet(int parent[], int i) {
    if (parent[i] == i) return i;
    return findSet(parent, parent[i]);
}

// Union of two sets (for Union-Find)
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = findSet(parent, x);
    int rootY = findSet(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Kruskal’s algorithm to find MST
void Graph::kruskalMST() {
    vector<Edge> edges;

    // Get all edges from adjacency list
    for (int u = 0; u < numVertices; u++) {
        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (u < v) { // To avoid adding edges twice
                edges.push_back({u, v, weight});
            }
        }
    }

    // Sort all edges in increasing order of their weights
    sort(edges.begin(), edges.end());

    // Create a parent and rank array for Union-Find
    int parent[numVertices], rank[numVertices];
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<Edge> mst; // To store MST edges
    for (Edge& e : edges) {
        int u = e.src, v = e.dest;
        if (findSet(parent, u) != findSet(parent, v)) {
            mst.push_back(e);
            unionSets(parent, rank, u, v);
        }
    }

    // Print the MST edges
    cout << "Kruskal's MST: \n";
    int mstWeight = 0;
    for (Edge& e : mst) {
        cout << "Edge: " << e.src << " - " << e.dest << " with weight " << e.weight << endl;
        mstWeight += e.weight;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

// Prim’s algorithm to find MST
void Graph::primMST() {
    // Array to store the minimum edge weight for each vertex
    int key[numVertices];
    int parent[numVertices];
    bool inMST[numVertices];

    // Initialize all keys to infinity
    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1; // No parent for root vertex

    // Minimum priority queue (key, vertex) based on key values
    for (int count = 0; count < numVertices - 1; count++) {
        int u = -1;

        // Find the vertex with minimum key value
        for (int v = 0; v < numVertices; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        // Add the vertex to MST
        inMST[u] = true;

        // Update the key values of adjacent vertices
        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // Print the MST edges
    cout << "Prim's MST: \n";
    int mstWeight = 0;
    for (int i = 1; i < numVertices; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " with weight " << key[i] << endl;
        mstWeight += key[i];
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    Graph g(V); // Create graph with 6 vertices (departments)

    // Add edges between departments with their corresponding weights (distances)
    g.addEdge(0, 1, 4); // CS to IT
    g.addEdge(0, 2, 7); // CS to EE
    g.addEdge(1, 3, 3); // IT to ME
    g.addEdge(1, 4, 8); // IT to CE
    g.addEdge(2, 3, 6); // EE to ME
    g.addEdge(2, 4, 5); // EE to CE
    g.addEdge(3, 5, 2); // ME to EC
    g.addEdge(4, 5, 3); // CE to EC

    // Call Kruskal’s algorithm
    g.kruskalMST();
    cout << endl;

    // Call Prim’s algorithm
    g.primMST();

    return 0;
}
