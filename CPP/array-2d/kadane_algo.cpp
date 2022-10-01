#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[], int n){
	int current=0;
	int largest=0;
	for (int i = 0; i < n; ++i)
	{
		current+=arr[i];
		if(current<0){
			current=0;
		}
		largest= max(current,largest);
	}
	return largest; 
}
void initial(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
int main(){
	
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<kadane(arr, n)<<endl;




	return 0;
}
