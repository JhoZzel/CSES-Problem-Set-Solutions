#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n; cin >> n;
    vector<pair<int,int>> order;
    set<int> S;
    S.emplace(0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        order.emplace_back(x, i);
    }
    sort(order.begin(), order.end());
    int i = 0;
    vector<int> ans(n + 1);
    while(i < n) {
        vector<int> pending;
        int j = i;
        while(j < n and order[i].first == order[j].first) {
            auto [val, pos] = order[j];
            auto it = S.upper_bound(pos);
            it--;
            ans[pos] = *it;
            pending.push_back(pos);
            j++;
        }
        for (int pos : pending) S.emplace(pos);
        i = j;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
 
    return 0;
}

