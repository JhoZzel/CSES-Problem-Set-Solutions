#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        long long x, y;
        cin >> x >> y;
        if (x > y) {
            if (x & 1) cout << x * (x - 1) + 1 - (x - y) << "\n";
            else cout << x * x - y + 1 << "\n";
        }
        else {
            if (y & 1) cout << y * y - x + 1 << "\n";
            else cout << y * (y - 1) + 1 - (y - x) << "\n";
        }
    }
    return 0;
}
