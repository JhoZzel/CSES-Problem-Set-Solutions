#include <bits/stdc++.h>
using namespace std;

int main() {
    string a; cin >> a;
    const int n = a.length();
    sort(a.begin(), a.end());
    bool can = n & 1;
    int i = 0;
    string p = "", mid = "";
    while(i < n - 1) {
        if (a[i] == a[i + 1]) {
            p += a[i];
            i += 2;
        }
        else {
            if (!can) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            mid = a[i];
            i++;
            can = false;
        }
    }
    if (can) mid = a[n - 1];
    cout << p + mid;
    reverse(p.begin(), p.end());
    cout << p << "\n";
    return 0;
}
