#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;

    vector<pair<int, int>> items(n); // {value, weight}
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; ++i)
        cin >> items[i].first >> items[i].second;

    // Sort by value/weight ratio (descending)                        
    //In C++, auto is a keyword that automatically figures out the                                                                           
            //data type based on what you assign to it .

    sort(items.begin(), items.end(), [](auto a, auto b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });

    double total = 0;

    for (auto [val, wt] : items) {
        if (W == 0) break;
        if (wt <= W) {
            total += val;
            W -= wt;
        } else {
            total += val * (double(W) / wt);
            break;
        }
    }

    cout << "Max value = " << total << endl;
    return 0;
}
