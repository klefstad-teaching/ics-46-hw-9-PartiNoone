#include "dijkstras.h"
// struct Edge:
// members: src, dst, weight
// operations: Edge(src,dst,weight), >>, <<

// struct Graph, inherits from vector<vector<Edge>>, which makes it a list of EdgeLists:
// members: numVertices
// operations: >> which adds verts to the graph, file_to_graph which puts the edges into graph

// todo
// vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous);
// vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination);
// void print_path(const vector<int>& v, int total);
