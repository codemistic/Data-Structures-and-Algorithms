#include <bits/stdc++.h>
using namespace::std;
#define endl '\n'
#define rep(i,a,b) for(int i=a; i < (b); ++i)
#define int long long

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n; cin >> n;
    vector<int> V(n); rep(i,0,n) cin>> V[i];
    sort(V.begin(),V.end());
    int res = 1;
    if (V[0] != 1) {
        cout << 1 << endl;
        exit(0);
    }
    for (int i = 0; i < n && V[i] <= res; ++i) {
        res += V[i];
    }
    cout << res << endl;
	return 0;
}
// 1 2 2 7 9
// Solution :- 
// we first check if we have a[0] = 1 then we can make sum = 1 else answer = 1
// we move ahead and now we have (1, [1] + 2 => [3] ) => { 1, 2 ,3 } sum we can make from a[0] to a[2]
// now similarly
// a[2] => [1,2,3] + 2 => 3,4,5
// a[3] => [1,2,3,4] + 7 => 8,9,10,11 so answer = 6
//https://medium.com/dexters-lab/eli5-find-the-smallest-positive-integer-value-that-cannot-be-represented-as-sum-of-any-subset-of-f8ea2488184b
