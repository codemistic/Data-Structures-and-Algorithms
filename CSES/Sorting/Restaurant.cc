#include "bits/stdc++.h"
#define int long long
using namespace::std;

signed main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; ++i) {
        int start, end; cin >> start >> end;
        v.push_back({start,+1});
        v.push_back({end,-1});
    }
    sort(v.begin(),v.end());
    vector<int> prefix(v.size()+1);
    prefix[0] = v[0].second;
    for (int i = 1; i < v.size(); ++i) {
        prefix[i] = prefix[i-1] + v[i].second;
    }
    cout << *max_element(prefix.begin(),prefix.end()) << endl;
	return 0;
}


