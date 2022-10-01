#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
bool issorted(int arr[],int i,int n){
	if(i==n-1)
		return true;
	if(arr[i+1]>arr[i] and issorted(arr,i+1,n))
		return true;
	return false;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int arr[]={1,2,3,4,5,3};
	int n;
	n=sizeof(arr)/sizeof(int);
	cout<<issorted(arr,0,n);
	
	return 0;
}
