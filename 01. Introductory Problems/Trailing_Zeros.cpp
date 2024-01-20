#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0, pot = 5;
    while(n / pot) {
        ans += (n / pot);
        pot *= 5;
    }
    cout << ans << "\n";
    return 0;
}
