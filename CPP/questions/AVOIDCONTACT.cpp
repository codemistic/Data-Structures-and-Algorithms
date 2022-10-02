//Ramnit here
#include<bits/stdc++.h>
using namespace std;

// typedef long long lolo;
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define all(v) v.begin,v.end()
// #define puba push_back
// #define F .first
// #define S .second

int main() {
	faster;
	int t;
    cin>>t;

    while(t--){
        int x,y;
        cin>>x>>y;
        if(x==y) cout<<(y*2)-1<<"\n";
        else cout<<(y*2)+(x-y)<<"\n";
    }
	return 0;
}
