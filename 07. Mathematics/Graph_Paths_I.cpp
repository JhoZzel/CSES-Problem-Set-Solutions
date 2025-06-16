#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

struct Matrix {
    int n;
    vector<vector<ll>> a;

    Matrix(int n) : n(n) {
        a.resize(n, vector<ll>(n, 0));
    }

    void id() {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                a[i][j] = (i == j);
    }

    vector<ll>& operator [] (int i) {
        return a[i];
    }

    Matrix operator + (Matrix &B) {
        Matrix C(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C.a[i][j] = (a[i][j] + B[i][j]) % MOD;
            }
        }
        return C;
    }

    Matrix operator * (Matrix &B) {
        Matrix C(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C.a[i][j] += a[i][k] * B.a[k][j] % MOD;
                    C.a[i][j] %= MOD;
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
    int n,m,k;
    cin >> n >> m >> k;
    Matrix A(n);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        A[u][v] += 1;
    }
    Matrix R = bpow(A, k);
    cout << R[0][n - 1] << "\n";
    return 0;
}
