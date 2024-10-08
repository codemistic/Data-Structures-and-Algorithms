#include "bits/stdc++.h"
#define int long long
using namespace::std;

signed main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n; cin >> n;
    std::vector<int> v(n); 
    map<int,int>m;
    int ans = 1;
    for (int &x: v) cin >> x, --x;
    for (int i = 0; i < n; ++i) { m[v[i]] = i; }
    for (int i = 1; i < n; ++i) {
        ans += (m[i] < m[i-1]);
    }
    cout << ans << endl;
	return 0;
}

// main observation is 
// if a number x come before x + 1 then no extra move required but otherwise we need extra move
