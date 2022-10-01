#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int *p;
    char *q;
    float *r;
     p= new int(10);
     q= new char('x');
     r= new float(16.6);
     cout<<sizeof(p)<<endl;
     cout<<sizeof(*p)<<endl;
     cout<<*p<<" "<<*q<<" "<<*r<<" "<<endl;
    return 0;
}


