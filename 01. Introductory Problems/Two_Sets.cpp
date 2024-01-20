#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main() {
    int n; cin >> n;
    ll mid_sum = 1ll * n * (n + 1) / 2;
    if (mid_sum & 1) {
        cout << "NO\n";
        return 0;
    }
    mid_sum >>= 1;
    
    cout << "YES\n";
    ll sa = 0;
    int i = n;
    while(sa + i < mid_sum) sa += i--;
    
    int target = mid_sum - sa;
    
    cout << i - 1 << "\n";
    for (int j = 1; j <= i; j++) {
        if (j == target) continue;
        cout << j << " \n"[j == i];
    }
    
    cout << n - i + 1 << "\n";
    cout << target << " ";
    for (int j = i + 1; j <= n; j++) {
        cout << j << " ";
    }
    
    return 0;
}
