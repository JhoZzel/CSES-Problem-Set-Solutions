#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

struct node {
    int key;
    int pr;
    int cnt;
    bool inv;
    ll sum;
    node *left, *right;
    node(int x) {
        key = x;
        cnt = 1;
        inv = 0;
        sum = x;
        pr = random(0, 1e9);
        left = right = nullptr;
    }
};

int sz(node *t) {
    return t ? t->cnt : 0;
}

ll get_sum(node *t) {
    return t ? t->sum : 0ll;
}

void update(node *t) {
    if (!t) return;
    t->cnt = sz(t->left) + 1 + sz(t->right);
    t->sum = get_sum(t->left) + t->key + get_sum(t->right);
}

void push(node *t) {
    if (!t or !t->inv) return;
    swap(t->left, t->right);
    if (t->left) t->left->inv ^= 1;
    if (t->right) t->right->inv ^= 1;
    t->inv = 0;
}

pair<node*, node*> split(node *t, int k) { 
    push(t);
    if (k == 0) return {nullptr, t};
    node *l,*r;
    if (k < sz(t->left) + 1) {
        r = t;
        auto [L, R] = split(t->left, k); 
        r->left = R;
        l = L;
    } else {
        l = t;
        auto [L, R] = split(t->right, k - sz(t->left) - 1);
        l->right = L;
        r = R;
    }
    update(l); update(r);
    return {l, r};
}

node* merge(node *l, node *r) {
    push(l); push(r);
    if (!l) return r;
    if (!r) return l;
    node* t;
    if (l->pr > r->pr) {
        t = l;
        t->right = merge(l->right, r);
    } else {
        t = r;
        t->left = merge(l, r->left);
    }
    update(t);
    return t;
}

void heapify(node *t) { 
    if (!t) return;
    node *mx = t;
    if (t->left and t->left->pr > mx->pr) 
        mx = t->left;
    if (t->right and t->right->pr > mx->pr) 
        mx = t->right;
    if (mx != t) {
        swap(t->pr, mx->pr);
        heapify(mx);
    }
}

node* build(vector<int> &a, int l, int r) { 
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    node *t = new node(a[mid]);
    t->left = build(a, l, mid - 1);
    t->right = build(a, mid + 1, r);
    heapify(t);
    update(t);
    return t;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &e : a) cin >> e;

    node *t = build(a, 0, n - 1);
    while(q--) {
        int op,i,j; 
        cin >> op >> i >> j;

        auto [L, r] = split(t, j);
        auto [l, mid] = split(L, i - 1);

        if (op == 1) {
            mid->inv = 1;
        } else {
            cout << mid->sum << "\n";
        }
        t = merge(l, mid);
        t = merge(t, r);
    }

    return 0;
}
