#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    double ratio1 = (double)a.first / a.second;
    double ratio2 = (double)b.first / b.second;
    return ratio1 > ratio2;
}

int main() {
    int n, c;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> c;

    vector<pair<int, int>> items(n); // প্রতিটি জোড়ায়: {মান, ওজন}

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    // রেশিও অনুযায়ী বড় থেকে ছোট সাজানো
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    for (int i = 0; i < n; i++) {
        int value = items[i].first;
        int weight = items[i].second;

        if (c == 0) break;

        if (weight <= c) {
            maxValue += value;         // পুরো আইটেম নেই
            c -= weight;
        } else {
            // আংশিক আইটেম নেই
            maxValue += value * ((double)c / weight);
            break;
        }
    }

    cout << "Max value = " << maxValue << endl;
    return 0;
}
