#include "dijkstras.h"
// struct Edge:
// members: src, dst, weight
// operations: Edge(src,dst,weight), >>, <<

// struct Graph, inherits from vector<vector<Edge>>, which makes it a list of EdgeLists:
// members: numVertices
// operations: >> which adds verts to the graph, file_to_graph which puts the edges into graph

// todo
// vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
//     int numVertices = graph.size(); // todo: probably get graph.size() * graph[1].size();
//     vector<int> distances(numVertices, INF); // todo: define inf
//     vector<bool> visited(numVertices, false);
//     distances[source] = 0;
//     previous[source] = UNDEFINED;
//     priority_queue<pair<int,int>> minHeap; // pair<vertex, weight>
//     minHeap.push({source, 0});
//     while (! minHeap.empty() ) {
//         int u = minHeap.extractVertexWithMinimumWeight().first; // define this func
//         if (visited[u]) continue;
//         visited[u] = true;
//         for (Edge edge: graph[u]){
//             int v = edge.dest;
//             int weight = edge.second;
//             if (!visited[v] && distances[u] + weight < distances[v]){
//                 distances[v] = distances[u] + weight;
//                 previous[v] = u;
//                 minHeap.push({v, distances[v]});
//             }
//         }
//     }
//     return distances;
// }


// vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination);
// void print_path(const vector<int>& v, int total);
