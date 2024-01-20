#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
        if (x > y) {
            if (x & 1) cout << x * (x - 1) + 1 - (x - y);
            else cout << x * x - y + 1;
        }
        else {
            if (y & 1) cout << y * y - x + 1;
            else cout << y * (y - 1) + 1 - (y - x);
        }
    }
    return 0;
}
