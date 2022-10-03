#include <bits/stdc++.h>
using namespace std;

int countTrailingZeroes(int n)
{
   int c =1;
   int countZeroes = 0;
   while((n/(pow(5,c)))){
       countZeroes += (n/(pow(5,c)));
       c++;
   }
   return countZeroes;
}

int main()
{
    int n;
    cin >> n;
    cout << countTrailingZeroes(n);
    return 0;
}