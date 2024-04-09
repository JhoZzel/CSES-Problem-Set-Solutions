#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;

int SD[MAX];

void sieve() { 
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
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
