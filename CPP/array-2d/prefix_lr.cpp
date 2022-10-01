#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i=a;i<b;i++)
#define vfr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define read(x) int x;cin>>x
const int N=1e5+10;
int arr[N];

using namespace std;
int main(){
	read(n);
	for (int i = 1; i <=n; ++i)
	{
		cin>>arr[i];
	}
	read(t);
	while(t--){
		read(l);read(r);
		ll sum=0;
		for (int i = l; i <= r; ++i)
		{
			sum+=arr[i];
		}			
		cout<<sum<<endl;
	}

	return 0;
}
