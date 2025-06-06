#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;

    set<int> S;
    for (int i = 0; i <= k; i++) S.emplace(i);
    vector<int> freq(k + 1);

    auto add = [&](int x) {
        if (x > k) return;
        if (freq[x]++ == 0) S.erase(x);
    };

    auto remove = [&](int x) {
        if (x > k) return;
        if (--freq[x] == 0) S.emplace(x);
    };

    for (int i = 0; i < k - 1; i++) add(a[i]);
    for (int i = k - 1; i < n; i++) {
        int j = i - k + 1;
        add(a[i]);
        cout << *S.begin() << ' ';
        remove(a[j]);
    }

    return 0;
}
