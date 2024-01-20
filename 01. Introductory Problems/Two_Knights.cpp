#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    for (int k = 1; k <= n; k++) {
        long long total = 1ll * k * k * (k * k - 1) / 2;
        long long atack = 4 * (k - 1) * (k - 2);
        cout << total - atack << "\n";
    }
    return 0;
}
