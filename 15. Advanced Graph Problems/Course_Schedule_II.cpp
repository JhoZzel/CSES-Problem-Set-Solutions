#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;

int n,m;
int out[N];
vector<int> G[N];

// Minimal Labels

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        out[u] += 1;
        G[v].emplace_back(u);
    }

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (out[i] == 0) pq.push(i);
    }
    
    vector<int> order;
    while(!pq.empty()) {
        int u = pq.top(); pq.pop();
        order.push_back(u);
        for (int v : G[u]) {
            if (--out[v] == 0) pq.push(v);
        }
    }
    reverse(order.begin(), order.end());
    for (int u : order) cout << ++u << " ";

    return 0;
}
