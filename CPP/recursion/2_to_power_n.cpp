#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
int func(int n){
	if(n==0)
		return 1;
	return (2*func(n-1));
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	int ans;
	cout<<func(n);

	
	return 0;
}
