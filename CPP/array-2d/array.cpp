#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	// char arr[n];
	// for (int i = 0; i < n; ++i)
	// {
	// 	cin>>arr[i];
	// }
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<arr[i];
	// }


	//2D array
	int arr[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>arr[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
