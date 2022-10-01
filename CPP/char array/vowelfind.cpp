#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
string vowel(string s){
    int n;
    n=s.size();
    string str;

    for (int i = 0; i < n; i++) {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u')
            str.push_back(s[i]);
    }
    return str;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    cout<<vowel(s);
    return 0;
}


