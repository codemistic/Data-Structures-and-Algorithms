#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9+7;
ll mod = 998244353;
 
void lookup(){
    ll n, k;
    cin>>n>>k;
    ll sum = 0;
    string s;
    ll val;
    unordered_map<string, ll> mp;
    for(int i = 0; i < n; i++){
        cin>>s>>val;
        sum += val;
        mp[s] += val;
    }
    if(k >= mp.size()){
        cout<<sum<<endl;
        return;
    }
 
    priority_queue<ll> pq;
 
    for(auto i: mp) pq.push(i.second);
 
    ll ans = 0;
    while(k--){
        ans += pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
}
 
int main(){
    lookup();
    return 0;
} 
