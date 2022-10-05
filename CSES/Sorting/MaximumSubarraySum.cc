#include <bits/stdc++.h>
using namespace::std;
#define endl '\n'
#define rep(i,a,b) for(int i=a; i < (b); ++i)
#define int long long

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int ans = -1e10;
    int curr = 0;
    int n; cin >> n;
    vector<int> v(n);
    rep(i,0,n) cin >> v[i];
    rep(i,0,n) {
        curr = max(v[i], curr + v[i]);
        ans = max(ans, curr);
    }
    cout << ans << endl;
	return 0;
}


