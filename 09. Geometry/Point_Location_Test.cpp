#include <bits/stdc++.h>
using namespace std;

#define x real()
#define y imag()

using ll = long long;
using Point = complex<ll>;

ll cross(Point a, Point b) { return imag(conj(a) * b); }

Point read() {
    int p,q;
    cin >> p >> q;
    return Point(p, q);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        Point A = read();
        Point B = read();
        Point P = read();
        
        ll sgn = cross(B - A, P - A);
        if (sgn == 0) cout << "TOUCH\n";
        else if (sgn > 0) cout << "LEFT\n";
        else cout << "RIGHT\n";
    }
    return 0;
}
