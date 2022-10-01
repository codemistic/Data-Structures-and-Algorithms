#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
string compressString(string s){
    int n=s.length();
    string ans;
    for (int i = 0; i < n; i++) {
        int count=1;
        while(s[i]==s[i+1] && i<n-1){
            count++;
            i++;
        }
        ans+=s[i];
        ans+=to_string(count);
    }
    if(ans.length()<s.length())
        return ans;
    else
        return s;
    
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s1 ="aaabbccddee";
    cout<< compressString(s1)<<endl;
    string s2="abcd";
    cout<< compressString(s2)<<endl;
    return 0;
}


