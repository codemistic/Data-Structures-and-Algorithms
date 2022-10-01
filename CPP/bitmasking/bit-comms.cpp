#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a;
    a=5;
    int b;
    b=10;
    cout<<a<<" and "<<b<<" is "<<(a&b)<<endl;//bitwise and - when both the bits are true then return true
    cout<<a<<" or "<<b<< " is "<<(a|b)<<endl;//bitwise or - when anyone of the bit is true then returs 1
    cout<<a<<" xor "<<b<<" is "<<(a^b)<<endl;//bitwise xor - when both the bits are same then returns 0

    //bitwise complement operator 
    cout<<"~( a) is "<<~(a)<<endl;

    //left and right shift operator
    a=5;
    b=2;
    cout<<"left shift = "<<(a<<b)<<endl;
    //left shift all the bits by the factor of b  [=a*2^b]
    //right shift all the bits by the faccor of b [=a/2^b]
    cout<<"right shift = "<<(a>>b)<<endl;

    return 0;
}


