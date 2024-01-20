#include <bits/stdc++.h>
using namespace std;

int main() {
    string a; cin >> a;
    set<string> ans;
    sort(a.begin(), a.end());
    do {    
        ans.insert(a);
    } while(next_permutation(a.begin(), a.end()));
    
    cout << ans.size() << "\n";
    for (string s : ans) {
        cout << s << "\n";
    }
    return 0;
}
