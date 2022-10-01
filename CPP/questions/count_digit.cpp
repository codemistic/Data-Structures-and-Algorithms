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
    int count=0;
    while(n>0){
        count++;
        n/=10;
    }
    cout <<"total digit in number is: "<< count << endl;
    return 0;
}


