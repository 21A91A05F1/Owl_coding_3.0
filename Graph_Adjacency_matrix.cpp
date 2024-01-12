#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // adjacency list for undirected graph
    // using a vector of vectors
    vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // this statement will be removed in case of directed graph
    }

    // Print the adjacency list
    for (int i = 1; i <= n; i++) {
        cout << "Adjacency list for vertex " << i << ": ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
4 5
1 2 
2 3
3 4
4 2
1 4
Adjacency list for vertex 1: 2 4 
Adjacency list for vertex 2: 1 3 4 
Adjacency list for vertex 3: 2 4 
Adjacency list for vertex 4: 3 2 1 

*/
