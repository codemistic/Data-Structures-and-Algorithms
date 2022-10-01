#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    char a[1000]="apple";
    char b[1000];
    cout<<strlen(a)<<endl; // to get the length of the string 
                           //
    strcpy(b,a);  //copy string to another variale 
    cout<<b<<endl;

    cout<<strcmp(a,b)<<endl;
    char br[]=" matlab seb hota hai";
    char z[222];
    strcpy(z,strcat(a,br));
    cout<<z<<endl;
    return 0;
}


