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
    int ans=0;
    while(n!=0){
        ans=ans*10+(n%10);
        n/=10;
    }
    if(ans==temp)
        cout<<"it is palindrome "<<endl;
    else
        cout<<"it is not pali"<<endl;
    
    return 0;
}


