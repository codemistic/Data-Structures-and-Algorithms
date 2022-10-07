//Infinite Replacement Codeforces

#define ll long long int
#define sc ;
#define tc ll t sc cin>>t sc while (t--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fin f(i,0,n)
#define V vector<int>
#define sis string s sc cin>>s;
#define  fastIO  ios_base::sync_with_stdio(0); cin.tie(0);
#include <bits/stdc++.h>
using namespace std;
static const int mod=1e9+7;

int main(){
    tc{
        sis;
        string t;
        cin>>t;
        int cnt=0;
        if(t.length()==1 && t[0]=='a') cout<<1<<endl;
        else {
        for(int i=0;i<t.length();i++){
            if(t[i]=='a') cnt++;
        }
        if(cnt>0) cout<<-1<<endl;
        else{
            long long ans=1;
            for(int i=0;i<s.length();i++){
                ans=ans*2;
            }
            cout<<ans<<endl;
        }
        }
    }
    return 0;
}
