#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
struct MAX_Queue {
    deque<ll> dq;
    
    MAX_Queue() {}
 
    void push(ll x) {
        while(!dq.empty() and x > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void pop(ll x) {
        if (dq.front() == x) {
            dq.pop_front();
        }
    }
    ll query() {
        return dq.front();
    }
};
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n,l,r;
    cin >> n >> l >> r;
 
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }
 
    MAX_Queue dq;
    ll ans = LLONG_MIN;
    for (int i = l; i <= n; i++) {
        dq.push(-pre[i - l]);
        ans = max(ans, pre[i] + dq.query());
        if (i - r >= 0) dq.pop(-pre[i - r]);
    }
    cout << ans << "\n";
 
    return 0;
}
