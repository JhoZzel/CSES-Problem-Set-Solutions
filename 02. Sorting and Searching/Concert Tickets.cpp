#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h.emplace(-x);
    }
    vector<int> t(m);
    for (int &e : t) cin >> e;
    
    for (int i = 0; i < m; i++) {
        auto it = h.lower_bound(-t[i]);
        if (it == h.end()) cout << "-1\n";
        else {
            cout << -(*it) << "\n";
            h.erase(it);
        }
    }
    return 0;
}
