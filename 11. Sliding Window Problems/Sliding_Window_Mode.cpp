#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    set<pair<int,int>> S;

    map<int,int> freq;

    auto add = [&](int x, int d) {
        if (freq[x]) S.erase(pair{-freq[x], x});   
        freq[x] += d;
        if (freq[x]) S.emplace(-freq[x], x);
    };

    for (int i = 0; i < k - 1; i++) add(a[i], 1);
    for (int i = k - 1; i < n; i++) {
        int j = i - k + 1;
        add(a[i], 1);
        cout << S.begin()->second << " ";
        add(a[j], -1);
    }

    return 0;
}
