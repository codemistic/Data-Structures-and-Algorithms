#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cout<<"Enter first number of rows and then columns"<<endl;
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

int i=0;
int arr[n][m];
while (i<n)
{
	int j=0;
	
	while (j<m)
	{
		
		cin>>arr[i][j];
		++j;
	}
	++i;
}

	//2D array
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		cin>>arr[i][j];
	// 	}
	// }
	cout<< "Array of "<<n<<" rows and "<<m <<" columns"<<endl;
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
