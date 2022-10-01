#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	int temp=n;
	int tmep2=n;
	int sum=0;
	int digit=0;
	while(n!=0){
		digit++;
		n/=10;
	}
	while(temp!=0){
		int ss=temp%10;
		sum+=pow(ss,digit);
		temp/=10;


	}
	if(sum==tmep2){
		cout<<"it is armstrong numbr"<<endl;

	}
	else
		cout<<"its not "<<endl;
	
	return 0;
}
