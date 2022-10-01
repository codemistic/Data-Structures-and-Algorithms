#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
bool isPalindrome(string s){
    int x;
    x=s.length();
    for(int i=0;i<x;i++){
        if(s[i]!=s[x-i-1])
            return false;
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    int n=isPalindrome(s);
    if(n)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
    return 0;
}


