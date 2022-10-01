#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
bool isPalindrome(char s[],int i,int n){
    if(i>=n/2)
    	return true;
    if(s[i]!=s[n-i-1])
    	return false;
    return isPalindrome(s,i+1,n);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	char str[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>str[i];
		
	}
	if(isPalindrome(str,0,n))
		cout<<"its a palli"<<endl;
	else
		cout<<"its not palli "<<endl;
	return 0;
}
