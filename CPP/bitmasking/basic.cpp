#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cout<<INT_MAX<<endl;
    //int a= (1>>32)-1;//here we can not store cause first 2^32 have 33 digit then it will subs 1 so it need space for 2^32
    unsigned int a=(1>>32)-1;
    cout<<a<<endl;
     //2^32 have 33 digit which can not be store in int because it can store only 32 digit
     //there are two types of int 1. signed int (simply --int)
     //in signed int we can only store 31 bits cause in this 1 bit is reserved for the sign i.e + /-
     //2. unsigned int in this we can store 32 bits as it have no sign its always +ve
     
    return 0;
}


