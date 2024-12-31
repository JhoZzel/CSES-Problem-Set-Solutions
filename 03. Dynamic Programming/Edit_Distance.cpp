#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 5;

int n,m;
string a,b;
int dp[N][N];

int f(int i, int j) {
    if (i == n) return m - j;
    if (j == m) return n - i;
    if (~dp[i][j]) return dp[i][j];
    int &ans = dp[i][j];
    if (a[i] == b[j]) {
        ans = f(i + 1, j + 1);
    } else {
        ans = 1 + min({f(i + 1, j), f(i, j + 1), f(i + 1, j + 1)});
    }
    return ans;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    memset(dp,-1,sizeof(dp));
    cin >> a >> b;
    n = a.size();
    m = b.size();
    cout << f(0, 0) << '\n';
    return 0;
}
