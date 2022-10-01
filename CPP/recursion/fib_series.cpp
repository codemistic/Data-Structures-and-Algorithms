#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void fib(int arr[],int n){
	arr[0]=0;
	arr[1]=1;
	for (int i = 2; i <= n; ++i)
	{
		arr[i]=arr[i-1]+arr[i-2];

	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	int arr[n];
	fib(arr,n);
	for (int i = 0; i <=n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
