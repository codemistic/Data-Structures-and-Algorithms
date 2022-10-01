#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
int getIthBit(int n,int i){
    int mask=(1<<i);
    return (n&mask)>0 ? 1:0;
}
void setIthBit(int &n,int i){
    int mask=(1<<i);
    n=(n|mask);
}
void clearIthBit(int &n,int i){
    int mask =~(1<<i);
    n=n&mask;
}
void updateIthBit(int &n,int i,int v){
    clearIthBit(n,i);
    int mask=(v<<i);
    n=n|mask;
}
void clearLastIthBit(int &n,int i){
    int mask= (-1<<i);
    n=n&mask;
}
void clearBitInRange(int &n,int i,int j){
int a=(~0)<<(j+1);
int b=(1<<i)-1;
int mask= a|b;
n=n&mask;
}
int main(){
    //:w
    //cin.tie(0)->sync_with_stdio(0);
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    int i;
    cout<<"enter the pos of bit: "<<endl;
    cin>>i;
    clearBitInRange(n,i,3);
    cout<<n<<endl;
    
    return 0;
}


