#include<bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    const int n = s.length();
    int xam = 1, len = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) len++;
        else {
            xam = max(xam, len);
            len = 1;
        }
    }
    cout << max(xam, len) << "\n";
    return 0;
}
