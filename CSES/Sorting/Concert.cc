#include <bits/stdc++.h>
using namespace::std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n, m; cin >> n >> m;
    multiset<int> x;
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        x.insert(l);
    }

    for (int i = 0; i < m; ++i) {
        int val; cin >> val;
        auto it = x.upper_bound(val);
        if (it == x.begin()) {
            cout << -1 << endl;
        } else {
            --it;
            cout << *it << endl;
            x.erase(it);
        }
    }
	return 0;
}


// 5 3 7 8 5
// 4 8 3
// 3 5 5 7 8 
