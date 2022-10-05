#include "bits/stdc++.h"
#define int long long
using namespace::std;

signed main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int x, n; cin >> x >> n;
    set<int> lights{0,x};
    multiset<int>dist{x};

    for(int i = 0; i < n; ++i){
        int pos; cin >> pos;
        auto it1 = lights.upper_bound(pos);
        auto it2 = it1;
        --it2;

        dist.erase(dist.find(*it1 - *it2));
        dist.insert(pos - *it2);
        dist.insert(*it1 - pos);
        lights.insert(pos);

        auto ans = dist.end();
        --ans;
        cout << *ans << " ";
    }
    return 0;
}
// if our max is on left side and element add on right no affect else affect
// 1 2 3 4 5 6 7 8
// 3 
// 1 2 | 4 5 6 7 8 
