#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    string s; cin >> s;
    string ans;
    set<char> S; 
    for (char c : s) {
        S.emplace(c);
        if ((int)S.size() == 4) {
            ans.push_back(c);
            S.clear();
        }
    }

    for (char c : "ACGT") {
        bool ok = 1;
        for (char x : S) if (c == x) ok = 0;
        if (ok) {
            ans.push_back(c);
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
