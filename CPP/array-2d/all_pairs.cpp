#include<bits/stdc++.h>
using namespace std;
int all_pair(int arr[], int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j=i+1 ; j < n; ++j)
		{
			cout<<arr[i]<<", "<<arr[j]<<endl;
		}
	}
	return 0;
}

int main(){
		int n;
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		all_pair(arr, n);

	return 0;
}
