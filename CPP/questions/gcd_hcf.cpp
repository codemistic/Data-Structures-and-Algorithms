#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
int gcdeuclid(int a,int b)
{
	if(b==0)
		return a;
	return gcdeuclid(b,a%b);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int a,b;
	cin>>a>>b;
	int ans;
	for (int i =1; i<=min(a,b); ++i)
	{
		if(a%i==0 && b%i==0)
			ans=i;
	}
	cout<<"using brute force gcd : "<<ans<<endl;
	cout<<"gcd of nums are : "<<gcdeuclid(a,b);
	
	return 0;
}
