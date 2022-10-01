#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    cin.get();
    char a[1000];
    char largest[10000];
    int large=0;
    while(n--){
        cin.getline(a,1000);
        int ln;
        ln=strlen(a);
        if(ln>large){
            large=ln;
            strcpy(largest,a);
        }
    }
    cout<<largest<<endl;
    return 0;
}


