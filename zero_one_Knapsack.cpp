#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n) {
    if (n == 0 || W == 0)
        return 0;

    int pick = 0;

    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1);

    int notPick = knapsackRec(W, val, wt, n - 1);

    return max(pick, notPick);
}

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    return knapsackRec(W, val, wt, n);
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
