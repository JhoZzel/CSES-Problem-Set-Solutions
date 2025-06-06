#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

const int B = 448;
const int N = 2e5 + 5;
const int INF = 1e9 + 9;

int n,q;
int a[N];
int id[N];
int cnt[N];
int sum[B];
vector<int> t;

struct Query {
    int l, r, x, y, idx;
    bool operator < (const Query other) const {
        int block_a = l / B, block_b = other.l / B;
        if (block_a != block_b) return block_a < block_b;
        return ((block_a & 1) ? (r > other.r) : (r < other.r)); 
    }
};

void add(int x, int d) {
    cnt[x] += d;
    sum[id[x]] += d;
}

int get_answer(int l, int r) {
    int ans = 0;
    if (id[l] == id[r]) {
        for (int k = l; k <= r; k++) {
            ans += cnt[k];
        }
    } else {
        for (int k = l; k < n; k++) {
            if (id[k] != id[l]) break;
            ans += cnt[k];
        }
        for (int k = id[l] + 1; k <= id[r] - 1; k++) {
            ans += sum[k];
        }
        for (int k = r; k >= 0; k--) {
            if (id[k] != id[r]) break;
            ans += cnt[k];
        }
    }
    return ans;
}

vector<int> mo_algorithm(vector<Query> Q) {
    vector<int> ans(size(Q));

    sort(Q.begin(), Q.end());
    int cur_l = 0, cur_r = -1;
    for (Query q : Q) {
        while (cur_l > q.l) {
            cur_l--;
            add(a[cur_l], 1);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(a[cur_r], 1);
        }
        while (cur_l < q.l) {
            add(a[cur_l], -1);
            cur_l++;
        }
        while (cur_r > q.r) {
            add(a[cur_r], -1);
            cur_r--;
        }
        ans[q.idx] = get_answer(q.x, q.y);
    }
    return ans;
}


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    for (int i = 0; i < N; i++) {
        id[i] = i / B;
    }

    cin >> n >> q;
    t.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t.push_back(a[i]);
    }
    t.push_back(INF);

    sort(all(t));
    t.erase(unique(all(t)), t.end());
        
    vector<Query> Q;
    for (int i = 0; i < q; i++) {
        int l,r,x,y;
        cin >> l >> r >> x >> y;
        l--; r--;
        x = lower_bound(all(t), x) - t.begin();
        y = upper_bound(all(t), y) - t.begin();
        y--;
        Q.push_back({l,r,x,y,i});
    }

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(t), a[i]) - t.begin();
    }

    vector<int> ans = mo_algorithm(Q);
    for (int i : ans) cout << i << '\n';

    return 0;
}
