#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
bool arePermutation(string a,string b){
   
    int n=a.length();
    int m=a.length();
    if(n!=m)
       return false;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for (int i = 0; i < n; i++) {
        if(a[i]!=b[i])
                return false;
    } 
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a,b;
    cin>>a>>b;
    cout<<arePermutation(a,b);
    return 0;
}


