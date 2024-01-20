#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a,b);
        if (2 * b - a >= 0 and (a + b) % 3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
