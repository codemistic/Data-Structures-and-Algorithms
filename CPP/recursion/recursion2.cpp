#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i=a;i<b;i++)
#define vfr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define read(x) int x;cin>>x
#define llread(x) long long x;cin>>x

using namespace std;
int array_sum(int n,int arr[]){
	if(n<0) return 0;
	return array_sum(n-1,arr)+arr[n];
}
int digit_sum(int n){
	if(n==0) return 0;
	return digit_sum(n/10)+ n%10;
}
int main(){
	read(n);
	cout<<digit_sum(n)<<endl;

		
	return 0;
}
