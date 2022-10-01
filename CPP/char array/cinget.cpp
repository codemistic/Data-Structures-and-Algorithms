#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define read(x) int x;cin>>x


using namespace std;
signed main(){
	char a[100];
	char temp=cin.get();
	int lenght=1;
	while(temp!='\n'){
		lenght++;
		cout<<temp;
		temp=cin.get();
	}
	cout<<endl<<lenght;

	
	return 0;
}
