#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 2e18;

struct Matrix {
    int n;
    vector<vector<ll>> a;

    Matrix() {}

    Matrix(int n) : n(n) {
        a.resize(n, vector<ll>(n, 0));
    }
    Matrix(int n, ll x) : n(n) {
        a.resize(n, vector<ll>(n, x));
    }
    
    void id() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = (i == j) ? 0 : INF;
            }
        }
    }

    vector<ll>& operator [] (int i) {
        return a[i];
    }

    Matrix operator * (Matrix &B) {
        Matrix C(n, INF);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] = min(C[i][j], a[i][k] + B[k][j]);
                }
            }
        }
        return C;
    }
    
    friend Matrix bpow(Matrix A, ll e) {
        const int n = A.a.size();
        Matrix R(n); R.id();
        while (e) {
            if (e & 1) R = R * A;
            A = A * A;
            e >>= 1;
        }
        return R;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n,m,k;
    cin >> n >> m >> k;

    Matrix A(n, INF);
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        A[u][v] = min<ll>(A[u][v], w);
    }

    Matrix R = bpow(A, k);
    ll ans = R[0][n - 1];
    cout << (ans == INF ? -1 : ans) << "\n";

    return 0;
}
