#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void reverse(int arr[],int s ,int e){
	if(s<e){
		swap(arr[s],arr[e]);
		reverse(arr,s+1,e-1);
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n ; ++i)
	{
		cin>>arr[i];

	}
	reverse(arr,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
