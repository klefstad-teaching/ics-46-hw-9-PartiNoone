#include "dijkstras.h"
// struct Edge:
// members: src, dst, weight
// operations: Edge(src,dst,weight), >>, <<

// struct Graph, inherits from vector<vector<Edge>>, which makes it a list of EdgeLists:
// members: numVertices
// operations: >> which adds verts to the graph, file_to_graph which puts the edges into graph

// bool cmp = [](pair<int,int> left, pair<int,int> right) { return left.second > right.second; };
// std::priority_queue<pair<int,int>, std::vector<pair<int,int>>, decltype(cmp)> lambda_priority_queue(cmp);


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int numVertices = G.size();
    vector<int> distances(numVertices, INF); // inf defined in .h
    vector<bool> visited(numVertices, false);
    distances[source] = 0;

    previous.assign(numVertices, UNDEFINED);
    // previous[source] = UNDEFINED;

    priority_queue<pair<int,int>, std::vector<pair<int,int>>, std::greater<pair<int, int>>> minHeap; // pair<weight, vertex>, defining the priority queue class?

    minHeap.push({0, source});
    while (! minHeap.empty() ) {
        int current = minHeap.top().second; // will .top work or should i do something?
        minHeap.pop();
        if (visited[current]) continue;
        visited[current] = true;
        for (Edge edge: G[current]){
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[current] + weight < distances[v]){
                distances[v] = distances[current] + weight;
                previous[v] = current;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    // todo: wth is previous
    vector<int> result;
    result.push_back(destination);
    int i = previous[destination];
    while (i != UNDEFINED){
        result.push_back(i);
        i = previous[i];
    }
    reverse(result.begin(), result.end());

    print_path(result, distances[destination]);
    return result; 
}

void print_path(const vector<int>& v, int total){
    for (int i: v)
        cout << i << ' ';
    cout << endl << "Total cost: " << total << endl;
}
