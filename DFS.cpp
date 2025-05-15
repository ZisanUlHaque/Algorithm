#include <bits/stdc++.h>
using namespace std;

string getColorWord(const string& status) {
    return status;
}

void dfsVisit(int node, vector<vector<int>>& adj, vector<string>& color, vector<int>& result) {
    color[node] = "gray";
    cout << "Visiting node: " << node << " (status: " << getColorWord("gray") << ")" << endl;

    for (int neighbor : adj[node]) {
        if (color[neighbor] == "white") {
            cout << "Discovered node: " << neighbor << " from " << node
                 << " (status: " << getColorWord("gray") << ")" << endl;
            dfsVisit(neighbor, adj, color, result);
        }
    }

    color[node] = "black";
    result.push_back(node);
    cout << "Finished node: " << node << " (status: " << getColorWord("black") << ")" << endl;
}

void dfs(int V, vector<vector<int>>& adj, int start) {
    vector<string> color(V, "white");
    vector<int> result;

    cout << "Starting DFS from node: " << start << " (status: " << getColorWord("gray") << ")" << endl;
    dfsVisit(start, adj, color, result);

    cout << "Final DFS order: ";
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
    cout << "Enter the starting node for DFS: ";
    cin >> start;

    dfs(V, adj, start);
    return 0;
}
