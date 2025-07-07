#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &e : a) cin >> e;

    int n1 = n / 2, n2 = n - n1;

    vector<ll> L;
    for (int mask = 0; mask < (1 << n1); mask++) {
        ll sa = 0;
        for (int i = 0; i < n1; i++) {
            if ((mask >> i) & 1) sa += a[i];
        }
        L.push_back(sa);
    }
    sort(L.begin(), L.end());

    vector<ll> R;
    for (int mask = 0; mask < (1 << n2); mask++) {
        ll sa = 0;
        for (int i = 0; i < n2; i++) {
            if ((mask >> i) & 1) sa += a[n1 + i];
        }
        R.push_back(sa);
    }
    sort(R.begin(), R.end());

    vector<pair<ll,int>> RR;
    for (int i = 0; i < sz(R); ) {
        int j = i;
        while(j < sz(R) and R[i] == R[j]) j++;
        RR.emplace_back(R[i], j - i);
        i = j;
    }

    ll ans = 0;
    int j = sz(RR) - 1;
    for (int i = 0; i < sz(L); i++) {
        while(j >= 0 and RR[j].first + L[i] > x) j--;
        if (j == -1) break;
        if (RR[j].first + L[i] == x) ans += RR[j].second;
    }
    cout << ans << "\n";


	return 0;
}
