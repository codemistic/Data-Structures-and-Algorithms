#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void Check(int n ){
	if(n%2==0 or n%3==0)
		cout<<"its not prime"<<endl;
	else
		cout<<"its prime"<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	Check(n);

	
	return 0;
}
