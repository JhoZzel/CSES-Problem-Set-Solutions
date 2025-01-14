#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
    
    ll S = 0;
    ll nS = 0;
    int j = 0;
    while (true) {
        while (j < n and a[j] <= S + 1) nS += a[j++];
        if (S == nS) break; 
        S = nS;
    }
    cout << S + 1 << '\n';

    return 0;
}
