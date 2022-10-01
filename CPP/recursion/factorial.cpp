#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
int sum=1;
void hehehe(int n)
{
	if(n==0) return;
	sum*=n;
	n--;
	hehehe(n);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	hehehe(n);
	cout<<sum<<endl;
	
	return 0;
}
