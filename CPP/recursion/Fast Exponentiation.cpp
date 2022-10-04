// program to find nth power of a number using optimized recursion (fast exponentiation)
#include<iostream>
using namespace std;

int fastExponent(int a, int b) {
    // base case
    if (b == 1) {
        return a;
    }
    int tempResult = fastExponent(a, b/2);
    // recursive relation
    if ((b & 1) == 0) {
        return (tempResult * tempResult);
    }
    else {
        return (a * (tempResult * tempResult));
    }
}

int main () {
  int base = 3, power = 11;
  cout<<base<<" raised to power "<<power<<" is: "<<fastExponent(base, power)<<endl;
  return 0;
}
