#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int n;
int dp[N];
vector<int> G[N];
 
int get_farthest(int s0) {
    queue<int> Q;
    Q.push(s0);
    vector<int> d(n,-1);
    d[s0] = 0;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : G[u]) {
            if (d[v] != -1) continue;
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
    int r = 0;
    int xam = -1;
    for (int i = 0; i < n; i++) {
        if (d[i] > xam) {
            xam = d[i];
            r = i;
        }
        dp[i] = max(dp[i], d[i]);
    }
    return r;
}
 
int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    get_farthest(get_farthest(get_farthest(0)));
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}
