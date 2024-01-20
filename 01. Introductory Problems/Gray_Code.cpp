#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> a(n);  
    for (int k = 1; k < n; k++) {
        int len = 1 << k;
        bool flip = true;
        for (int i = 0; i < (1 << n) / len + 1; i++) {
            a[k - 1] += string(len, flip ? '0' : '1');
            flip ^= 1; 
        }
        a[k - 1] = a[k - 1].substr(len >> 1, 1 << n);
    }
    a[n - 1] = string(1 << (n - 1), '0') + string(1 << (n - 1), '1');
   
    for (int j = 0; j < (1 << n); j++) {
        for (int i = n - 1; i >= 0; i--) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
