#include "dijkstras.h"

void test_dijkstras(){
    Graph G;
    file_to_graph("src/medium.txt", G);
    vector<int> prev;

    // 0, 5, 2, 3; total = 12
    vector<int> distances = dijkstra_shortest_path(G, 0, prev);
    vector<int> result = extract_shortest_path(distances, prev, 3);

    // 0, 5, 4; total = 10
    result = extract_shortest_path(distances, prev, 4);
    prev.clear();

    // 5, 2, 3; total = 10
    distances = dijkstra_shortest_path(G, 5, prev);
    result = extract_shortest_path(distances, prev, 3);
}

int main(){
    test_dijkstras();
}