//  2 ^ 11   ,  x^n
//    11 ->   1 0 1 1 ;
//  x = 2 , n=11 , res =1
// 11/2 = 5  -> 1    res = res*x =2     n=5;    x=x*x=4
//  5/2 = 2  -> 1    res = 2 *4 = 8     n=2     x = 16
// 2/2 =1    -> 0    res = 8     n=1     x = 16*16 =256
// 1/2 =0    -> 1    res = 8 *256     
    // res = 2 * 4 *256

#include <bits/stdc++.h>

using namespace std;

int IterativePower(int x,int n){
   int res = 1;
    while( n ){
        if(n & 1){
            res = res * x ;
        }
        x = x * x ;
        n = n>>1;
    }
    return res;
}

int main(){
int x,n;
cin>>x>>n;
cout<<IterativePower(x, n);
}
