#include <bits/stdc++.h>
using namespace std;
 
bool ask(int x) {
    cout << "? " << x << endl;
    string q; cin >> q;
    return (q == "YES");
}
 
int main() {
    int lo = 1, hi = 1e9;
    while(lo < hi) { // 1111000  
        int mid = (lo + hi) / 2;
        if (ask(mid)) lo = mid + 1;
        else hi = mid;
    }
    cout << "! " << lo << endl;
    return 0;
}
