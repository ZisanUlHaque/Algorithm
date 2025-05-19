#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];

void dfs(int src)
{
    cout << src << endl;
    vis[src] = true;
    for (int child : v[src])
    {
        if (!vis[child])
            dfs(child);
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of node: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter edges (a b):" << endl;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int start;
    cout << "Enter starting node for DFS: ";
    cin >> start;

    memset(vis, false, sizeof(vis));
    dfs(start);

    return 0;
}
