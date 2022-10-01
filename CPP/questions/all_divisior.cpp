#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	for (int i = 1; i < n; ++i)
	{
		if(n%i==0)
			cout<<i<<" ";
	}
	
	return 0;
}
