#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> m;

    vector<int> P(n + 1);  // P[1..n] for profits
    vector<int> wt(n + 1); // wt[1..n] for weights

    cout << "Enter profits of items:\n";
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 1; i <= n; i++) {
        cin >> wt[i];
    }

    // Create K[i][w] table (n+1) x (m+1)
    vector<vector<int>> K(n + 1, vector<int>(m + 1, 0));

    // Dynamic Programming logic (1-based)
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i] <= w) {
                K[i][w] = max(P[i] + K[i - 1][w - wt[i]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    cout << "Maximum profit: " << K[n][m] << endl;
    return 0;
}


