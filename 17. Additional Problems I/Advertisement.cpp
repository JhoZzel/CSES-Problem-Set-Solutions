#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9 + 9;

const int N = 2e5 + 5;

int n;
int a[N];
int L[N], R[N];

int main() {    
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[0] = a[n + 1] = -INF;

    stack<int> st;
    st.emplace(n + 1);
    for (int i = n; i >= 1; i--) {
        while(a[i] <= a[st.top()]) st.pop();
        R[i] = st.top() - 1;
        st.emplace(i);
    }
    
    while(!st.empty()) st.pop();

    st.emplace(0);
    for (int i = 1; i <= n; i++) {
        while(a[i] <= a[st.top()]) st.pop();
        L[i] = st.top() + 1;
        st.emplace(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, 1ll * a[i] * (R[i] - L[i] + 1));
    }
    cout << ans << "\n";

    return 0;
}
