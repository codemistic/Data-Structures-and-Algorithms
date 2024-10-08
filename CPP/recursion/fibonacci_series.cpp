// #include<iostream>
// using namespace std;
// int fib(int n){
//     if(n<=1)
//     return n;
//     else
//     return fib(n-2)+fib(n-1);
// }
// int main(){
//     cout<<fib(7);
//     return 0;
// }

// using iteration method//

// #include<iostream>
// using namespace std;
// int fib(int n){
//     if(n<=1)
//     return 1;
//     int t0=0,t1=1,s;
//     for(int i=2;i<=n;i++){
//       s=t0+t1;
//       t0=t1;
//       t1=s;
//     }
//     return s;
// }
// int main(){
//     cout<<fib(7);
//     return 0;
// }


//using memoization technique//


// #include<iostream>
// using namespace std;
// int F[10];
// int fib(int n){
//     if(n<=1){
//     F[n]=n;
//     return n;
//     }
//   else 
//   if(F[n-2]==-1){
//       F[n-2]=fib(n-2);
//   }
//   if(F[n-1]==-1){
//       F[n-1]=fib(n-1);
//   }
//   return fib(n-2)+fib(n-1);
// }
// int main(){
//     cout<<fib(7);
//     return 0;
// }