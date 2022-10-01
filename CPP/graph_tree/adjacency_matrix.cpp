#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int arr[n+1][n+1];
	for (int i = 0; i < m; ++i)
	{
		/* code */
		int u,v;
		arr[u][v]=1;
		arr[v][u]=1;
	}
	
	return 0;
}
