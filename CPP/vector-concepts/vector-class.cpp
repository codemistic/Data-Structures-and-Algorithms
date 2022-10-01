#include <bits/stdc++.h>
#include "vector.h"

using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    cout<<v.at(2)<<endl;
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    return 0;
}


