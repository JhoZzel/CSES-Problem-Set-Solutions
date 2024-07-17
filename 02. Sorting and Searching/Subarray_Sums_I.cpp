
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 2e5 + 5;
 
ll pre[N];
 
int main() {
    int n,S;
    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    int ans = 0;
    int i = 0, j = 0;
    while(i <= n) {
        while(j <= n && pre[j] - pre[i] < S) j++;
        while(j <= n && pre[j] - pre[i] == S) j++, ans++;  
        i++;
    }
    cout << ans << '\n';
    return 0;
}
