#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<bool> vis(n);
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        vis[x - 1] = true;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        cout << i + 1 << "\n";
        break;
    }
    return 0;
}
