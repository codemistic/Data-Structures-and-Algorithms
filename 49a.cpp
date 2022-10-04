#include<bits/stdc++.h>
using namespace std;
int main(){

string s;
getline(cin,s);

int l=s.length();
int f=0;
for (int i=l;i=0;i--){
if (s[i]!=' ' || s[i]!='?'){
    if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y' ){
       f=1;
       break;

    }
    else
   f=0;}}

   if (f==1){
        cout<<"YES"<<endl;
   }
    else
    cout<<"NO"<<endl;

   
    return 0;
}