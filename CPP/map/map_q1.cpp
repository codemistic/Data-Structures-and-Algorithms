/*
Given N strings, print unique strings
 in lexiographical order with their
 frequency
 N <=10^5
 |S| <=100
 */
#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define read(x) int x;cin>>x


using namespace std;
signed main(){
	map<string,int> m;
	int n;
	cin>>n;
	fr(i,0,n){
		string s;
		cin>>s;
		m[s]++;
	}
	for(auto it:m)
		cout<<it.first<<" "<<it.second<<endl;
	

	
	return 0;
}
