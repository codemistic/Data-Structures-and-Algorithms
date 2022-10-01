#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void rev_arr(int arr[],int i,int n)
{
	if(i>=n/2)
		return;
	swap(arr[i],arr[n-i-1]);
	rev_arr(arr,i+1,n);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];

	}
	rev_arr(arr,0,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}

	
	return 0;
}
