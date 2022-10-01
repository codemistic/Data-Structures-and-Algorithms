#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
int ref(int a, int b){
    int c=a%b;
    a/=10;
    cout<<c<<" "<<a;
    return 0;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int  x=10,y=2;
    ref(x,y);
    cout<<endl;
    ref(x+10,y);
    }
