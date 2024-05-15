#include <bits/stdc++.h>
using namespace std;
 
struct DynamicMedianMS {
    multiset<int> ms;
    multiset<int>::iterator med_it;
    int med_idx;
 
    DynamicMedianMS() : ms({-1}), med_it(ms.begin()), med_idx(0) {}
  
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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    DynamicMedianMS DMS;
    for (int i = 0; i < k; i++) DMS.insert(a[i]);
    cout << DMS.get() << ' ';
    for (int i = k; i < n; i++) {
        DMS.insert(a[i]);
        DMS.remove(a[i - k]);
        cout << DMS.get() << ' ';
    }
    return 0;
}
