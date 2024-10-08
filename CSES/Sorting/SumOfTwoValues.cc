#include <bits/stdc++.h>
using namespace::std;
#define endl '\n'
#define rep(i,a,b) for(int i=a; i < (b); ++i)

int main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n, x; cin >> n >> x;
    map<int,int>m; 
    vector<int> V;
    rep(i,0,n){
        int v; cin >> v;
        V.push_back(v);
        m[v] = i;
    }

    rep(i,0,n) {
        if (m.find(x - V[i]) != m.end() && m[x-V[i]]!=i) {
            cout << i+ 1 << " " << m[x-V[i]] + 1 << endl;
            exit(0);
        }
    }
    cout << "IMPOSSIBLE" << endl;
	return 0; 
}


