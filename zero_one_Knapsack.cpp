#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter values of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    cout << "Enter weights of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> wt[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    cout << "Maximum value in knapsack = " << knapsack(W, val, wt) << endl;

    return 0;
}

