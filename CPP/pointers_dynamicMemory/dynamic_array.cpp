#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    clrscr;
    cout<<"enter the n :"<<endl;cin>>n;
    int *p= new int[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for (int i = 0; i < n; i++) {
        cout<<*(p+i)<<" ";
    }    
    delete p;
    return 0;
}


