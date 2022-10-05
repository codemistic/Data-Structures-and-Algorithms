#include "bits/stdc++.h"
#define int long long
using namespace::std;

signed main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n; cin >> n;
    vector<int> v(n); 
    map<int,int>m;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int ans = 0;
    m[v[0]] = 1;
    int cnt = 0;
    for(int i = 1; i < n; ++i) {
        if (m.find(v[i])!=m.end()) {
            cnt++;
            ans = max(ans,m[v[i-1]]);
            m[v[i]] = (m[v[i-1]] + cnt - m[v[i]]);
        } else {
            m[v[i]] = m[v[i-1]] + 1;
        }
    }
    ans = max(ans,m[v[n-1]]);
    cout << ans << endl;
	return 0;
}

// 1 2 1 3 7 4 2 
// 1 2 | 3,4,5, ans = 5, 5 - 2=> 3
//    (3-1)
