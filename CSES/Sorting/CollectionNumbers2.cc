#include "bits/stdc++.h"
#define int long long
using namespace::std;

signed main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n,q; cin >> n >> q;
    std::vector<int> v(n); 
    for (int &x: v) cin >> x, --x;
    while (q--) {
        int a, b; cin >> a >> b;
        --a,--b;
        swap(v[a],v[b]);
        map<int,int>m;
        int ans = 1;

        for (int i = 0; i < n; ++i) { m[v[i]] = i; }
        for (int i = 1; i < n; ++i) {
            ans += (m[i] < m[i-1]);
        }
        cout << ans << endl;
    }
	return 0;
}

// bruteforce
// 4 2 1 5 3 
// 4 1 2 5 3  swap(i,k)
// a[i] and a[k] made affect on a[i-1] a[k-1] and a[i+1] a[k+1]
