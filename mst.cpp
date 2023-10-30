//minimum spanning tree

#include <iostream>

#include <vector>

#include <queue>

#include <utility>

using namespace std;

// Define a structure to represent edges

struct Edge {

    int to, weight;

    Edge(int t, int w) : to(t), weight(w) {}

};

// Define a function to implement Prim's Algorithm

vector<Edge> primMST(vector<vector<Edge>>& graph, int start) { // Fix the parameter type of primMST

    int n = graph.size();

    vector<bool> visited(n, false);

    vector<Edge> mst; // Minimum Spanning Tree

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Fix the priority_queue declaration

    pq.push({0, start});

    while (!pq.empty()) {

        int weight = pq.top().first;

        int vertex = pq.top().second;

        pq.pop();

        if (visited[vertex]) {

            continue;

        }

        visited[vertex] = true;

        mst.push_back(Edge(vertex, weight));

        for (Edge& edge : graph[vertex]) {

            if (!visited[edge.to]) {

                pq.push({edge.weight, edge.to});

            }

        }

    }

    return mst;

}

int main() {

    // Create an example graph represented as an adjacency list

    int n = 5;

    vector<vector<Edge>> graph(n);

    graph[0].push_back(Edge(1, 2));

    graph[1].push_back(Edge(0, 2));

    graph[1].push_back(Edge(2, 3));

    graph[2].push_back(Edge(1, 3));

    graph[0].push_back(Edge(3, 4));

    graph[3].push_back(Edge(0, 4));

    graph[3].push_back(Edge(2, 5));

    graph[2].push_back(Edge(3, 5));

    int start = 0;

    vector<Edge> mst = primMST(graph, start);

    cout << "Minimum Spanning Tree from vertex " << start << ":\n";

    for (Edge edge : mst) {

        cout << start << " - " << edge.to << " (Weight: " << edge.weight << ")\n";

    }

    return 0;

}