#include<bits/stdc++.h>
using namespace std;
int largestsubarray_sum(int arr[],int n){
	int largest_sum;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{	
			int super_sum=0;
			for (int k = i; k <= j; ++k)
			{
				super_sum+=arr[k];
			}
			largest_sum= max(largest_sum,super_sum);
			
		}
	}
	return largest_sum;
}
void initial(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
int main(){
	initial();
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<largestsubarray_sum(arr,n);

	return 0;
}
