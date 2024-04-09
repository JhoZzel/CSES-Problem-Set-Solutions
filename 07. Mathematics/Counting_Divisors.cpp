#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int SD[N];

void sieve() { 
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            SD[j]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cout << SD[x] << "\n";
    }

    return 0; 
}
