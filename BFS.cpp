#include <bits/stdc++.h>
using namespace std;

string getColorWord(const string& status) {
    return status; 
}

void bfs(int V, vector<vector<int>>& adj, int start) {
    vector<string> color(V, "white");
    queue<int> q;
    vector<int> result;

    q.push(start);
    color[start] = "gray";
    cout << "Starting BFS from node: " << start << " (status: " << getColorWord("gray") << ")" << endl;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        color[node] = "black";
        cout << "Visited node: " << node << " (status: " << getColorWord("black") << ")" << endl;
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (color[neighbor] == "white") {
                color[neighbor] = "gray";
                q.push(neighbor);
                cout << "Discovered node: " << neighbor << " from " << node
                     << " (status: " << getColorWord("gray") << ")" << endl;
            }
        }
    }

    cout << "Final BFS order: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    int start;
    cout << "Enter the starting node for BFS: ";
    cin >> start;

    bfs(V, adj, start);
    return 0;
}

