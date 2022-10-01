#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
int countBit(int n){
int count=0;
    while(n>0){
        int last=(n&1);
        count+=last;
        n=n>>1;
    }
    return count;
}
int countBit_fast(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1);
        ans++;
    }
    return ans;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    
    cout<<countBit(n)<<endl;
    cout<<countBit_fast(n)<<endl;
    return 0;
}


