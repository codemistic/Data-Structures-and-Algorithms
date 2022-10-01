#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void recursive_bubble(int arr[],int n){
	if(n==1)
		return;
	int count=0;
	for (int i = 0; i < n-1; ++i)
	{
		if (arr[i]>arr[i+1])
		{
			swap(arr[i],arr[i+1]);
			count++;
		}
	}

	if(count==0)
		return;
	recursive_bubble(arr,n-1);	

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
	recursive_bubble(arr,n);
	for (int i = 0; i < n; ++i)
		{
			cout<<arr[i]<<" ";
		}	
	return 0;
}
