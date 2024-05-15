#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9 + 9;

struct DynamicMedianMS {
    multiset<int> ms;
    multiset<int>::iterator med_it;
    int med_idx;
 
    DynamicMedianMS() : ms({-INF}), med_it(ms.begin()), med_idx(0) {}
  
    void insert(int x) {
        if(x < *med_it) med_idx++; // correct the index
        ms.insert(x);
        int idx = ms.size() / 2; // the index of real median
        if(med_idx < idx) med_it++;
        if(med_idx > idx) med_it--;
        med_idx = idx;
    }

    void remove(int x) {
        if (x <= *med_it) med_idx--; // correct the index
        if (ms.find(x) == med_it) {
            int idx = (ms.size() - 1) / 2;
            if (med_idx == idx) med_it--;
            else med_it++;
            med_idx = idx;
            ms.erase(ms.find(x));
            return;
        }
        ms.erase(ms.find(x));
        int idx = ms.size() / 2; // the index of real median
        if(med_idx < idx) med_it++;
        if(med_idx > idx) med_it--;
        med_idx = idx;
    }
    
    int get() {
        return *med_it;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    DynamicMedianMS DMS;
    
    ll fb = 0;
    ll fa = 0;

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int a,b;
            cin >> a >> b;
            fb += b;
            if (i == 0) {
                DMS.insert(a);
                continue;
            }
            int med_ant = DMS.get();
            DMS.insert(a);
            int med_cur = DMS.get();
            
            int delta = abs(med_ant - med_cur);
            if (med_ant < med_cur and DMS.ms.size() & 1) fa -= delta;
            if (med_cur < med_ant and DMS.ms.size() & 1) fa += delta;
            
            fa += abs(a - med_cur);
        }
        else {
            cout << DMS.get() << ' ' << fa + fb << '\n';
        }
    }
    return 0;
}
