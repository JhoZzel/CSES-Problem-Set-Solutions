#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int pre[N][N];

int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + (c == '*');
        }
    }
    while(q--) {
        int i1,j1,i2,j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << pre[i2][j2] - pre[i2][j1 - 1] - pre[i1 - 1][j2] + pre[i1 - 1][j1 - 1] << '\n';
    }
    return 0;
}
