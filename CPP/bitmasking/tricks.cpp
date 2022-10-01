#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    int x;
    cin>>x;
    if(x&1){
        cout<<"odd"<<endl;

    }
    else
        cout<<"even"<<endl;
    //multipling  a number by two using left and right shift ops
    cout<<(24<<1)<<endl;
    //division by 2
    cout<<(24>>1)<<endl;

    //changing a uper case to lower case
    char a;
    cin>>a;
    cout<<char(a|' ')<<endl;//basically we are set ing the 5th bit of the upper case char
                               //(1<<5) is 100000 which is 32 in decimal 
                               //system which denotes ' '(space) in ascii value
    //changing a lower case to uper case
    char e;
    cin>>e;
    // ~(1<<) is basically the char '_' (underscore)
    cout<<char(e&'_')<<endl;
    return 0;
}


