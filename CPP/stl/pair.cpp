#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //pair
    pair<int,int> p={1,3};
    cout<<p.first<<" "<<p.second<<endl;
   //nesting of pair
    pair<int,pair<int,int>> p1={1,{3,4}};
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
    // array of pair
    pair<int,int> arr[]={{1,2},{2,3},{4,5}};
    cout<<arr[1].first<<" "<<arr[1].second<<endl;

    return 0;
}


