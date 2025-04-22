#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 30;

int n,q;
int go[N][LOG];

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> go[i][0];
    }
    
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            go[i][j] = go[go[i][j - 1]][j - 1];
        }
    }

    while(q--) {
        int u,k;
        cin >> u >> k;
        for (int j = LOG - 1; j >= 0; j--) {
            if ((k >> j) & 1) {
                u = go[u][j];
            }
        }
        cout << u << "\n";
    }



    return 0;
}
