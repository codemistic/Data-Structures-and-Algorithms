#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 100000007
#define endl '\n'
const int N=1e7+10;
int hash_arr[N];
int main(){
	//cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	int arr[n];
	
	
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		hash_arr[arr[i]]++;

	}
	int q;cin>>q;
	while(q--){
		int i;cin>>i;
		cout<<hash_arr[i]<<endl;
	}	
	return 0;
}
