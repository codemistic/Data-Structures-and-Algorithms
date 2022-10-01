#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define read(x) int x;cin>>x


using namespace std;
signed main(){
	set<string> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string z;
		cin>>z;
		s.insert(z);
	}
	s.erase("abc");
	
	for(auto it:s)
		cout<<it<<endl;

	
	return 0;
}
