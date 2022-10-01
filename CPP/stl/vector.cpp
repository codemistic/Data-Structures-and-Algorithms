#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<int> v;
    v.pb(1);
    v.emplace_back(2);
    cout<<v[0]<<endl; 
    //vector or pair
    vector<pair<int,int>> vec;
    vec.pb({1,2});
    vec.emplace_back(1,2);
    cout<<vec[0].first<<" "<<vec[0].second<<endl;
    //iterator of the vector
    vec.pb({12,32});
    vector<int>::iterator it=v.begin();
    it++;
    cout<<*it<<" "<<*it;
    //initializing vector
    vector<int> v1(5);//vector with 5 value (0)
    vector<int > v2(5,43);//vector with 5 value that is 43 each 
    vector<int >::iterator it1=v.end();
    vector<int >::iterator it2=v.rend();
    vector<int >::iterator it3=v.rbegin() ;
    
    



    return 0;
}


