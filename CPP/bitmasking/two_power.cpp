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
    if((n &(n-1))==0){
        cout<<"it is a power of two"<<endl;

    }
    else
        cout<<"it is not"<<endl;
    return 0;
}


