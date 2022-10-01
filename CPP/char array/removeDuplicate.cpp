#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
string removeDuplicate(string s){
    //std::set<char> ch;
    set<char> ch (s.begin(),s.end()); //string to set conversion
    int n;
    //n=s.length();
      // for (int i = 0; i < n; i++)i{
        //   ch.insert(s[i]);
       //}
    string newstring; 
    for(auto &it:ch)
        newstring.push_back(it);
    return newstring;
    
}                       
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    cout<<removeDuplicate(s)<<endl;

    return 0;
}


