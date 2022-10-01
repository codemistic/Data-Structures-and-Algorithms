#include<bits/stdc++.h>
using namespace std;
int sub_array(int arr[], int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			for (int k = i; k < j; ++k)
			{
				
				cout<<arr[k]<<", ";
			}
			cout<<endl;
		}
	}
	return 0;

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
	sub_array(arr,n);

	return 0;
}
