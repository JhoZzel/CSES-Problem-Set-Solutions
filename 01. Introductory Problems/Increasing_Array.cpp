#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, last, cur;
    cin >> n >> last;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> cur;
        if (cur < last) ans += last - cur;
        else last = cur;
    }
    cout << ans << "\n";
    return 0;
}
