#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1000 + 5;

int n,m;
int a[N];
int b[N];
int dp[N][N];
vector<int> v;

int f(int i, int j) {
    if (i >= n or j >= m) return 0;
    if (~dp[i][j]) return dp[i][j];
    int &ans = dp[i][j] = 0;
    ans = max(ans, f(i + 1, j + 1) + (a[i] == b[j]));
    ans = max(ans, f(i + 1, j));
    ans = max(ans, f(i, j + 1));
    return ans;
}

void rec(int i, int j) {
    if (i >= n or j >= m) return;
    int ans = f(i, j);
    if (ans == f(i + 1, j + 1) + (a[i] == b[j])) {
        if (a[i] == b[j]) v.push_back(a[i]);
        rec(i + 1, j + 1);
    } else if (ans == f(i + 1, j)) {
        rec(i + 1, j);
    } else {
        rec(i, j + 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp,-1,sizeof(dp));
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    rec(0,0);
    cout << v.size() << "\n";
    for (int e : v) cout << e << " ";
    cout << "\n";
    return 0;
}
