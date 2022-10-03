//Ramnit here
#include<bits/stdc++.h>
using namespace std;

// typedef long long lolo;
#define fasterDaddy ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define all(v) v.begin,v.end()
// #define puba push_back
// #define F .first
// #define S .second

int main() {
	fasterDaddy;
	int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        if(n%2==1) cout<<"-1\n";
        else{
            string s="";
            for(int i=0;i<n;i++){
                if(i%2==1) s+="0";
                else s+="1";
            }
            cout<<s<<"\n";
        }
    }
	return 0;
}
