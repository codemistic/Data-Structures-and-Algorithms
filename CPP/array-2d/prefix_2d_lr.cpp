#include<bits/stdc++.h>
using namespace std;
const int n= 1e3+ 10;
int arr[n][n];
long long pr[n][n];
int main(){
int arr[n][n];

int n;
cin>>n;		
for (int i = 1; i <= n; ++i)
{
	for (int j = 1; j <=n; ++j)
	{
		cin>>arr[i][j];
		pr[i][j]=arr[i][j]+pr[i-1][j]+pr[i][j-1]-pr[i-1][j-1];
	}
}
int t;
cin>>t;
while(t--){
	int a,b,c,d;
	cin>>a>>b>>c>>d;

	cout<<pr[c][d]-pr[a-1][d]-pr[c][b-1]+pr[a-1][b-1]<<endl;
	
}


return 0;
}
