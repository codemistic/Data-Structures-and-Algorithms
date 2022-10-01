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
	cin.get(a,100);
	int n=strlen(a);
	int digit=0,alpha=0,space=0;
	for(int i=0;i<n;i++){
		if(a[i]>='0' && a[i]<='9')
			digit++;
		else if((a[i]>='a' and a[i]<='z') or (a[i]>='A' and a[i]<='Z'))
			alpha++;
		else if(a[i]==' ')
			space++;
	}
	cout<<a<<endl;
	cout<<"digits "<<digit<<endl;
	cout<<"alpha "<<alpha<<endl;
	cout<<"space "<<space<<endl;

	
	return 0;
}
