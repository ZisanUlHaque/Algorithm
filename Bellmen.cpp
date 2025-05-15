#include<bits/stdc++.h>
using namespace std;

int main() {
    int V,E;
    cout << "How many points (vertics) and paths (edges) ?";
    cin >> V >> E;

    vector<vector<int>>edges;
    cout << "Enter each path like this : from to weight\n";
    for(int i=0;i<E;i++){
        int from, to, weight;
        cin >> from >>to >> weight;
        edges.push_back({from,to,weight});
    }

    int start;
    cout << "which point to start from? ";
    cin >> start;

    vector<int> dist(V,100000);
    dist[start] = 0;

    for (int i = 0; i < V-1; i++)
    {
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] + w<dist[v]){
                dist[v] = dist[u] + w;
            }
        }
        
    }

    for (auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dist[u] + w<dist[v]){
            cout << "Negative cycle found/n";
            return 0;
        }
    }
    
    cout<<"Shortest distance:\n";
    for (int i = 0; i < V; i++)
    {
        cout <<"From" << start <<"to" <<i <<"="<<dist[i]<<"\n";
    }
    
    return 0;
}