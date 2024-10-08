// You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int rev = 0;
    while (n != 0)
    {
        int rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    cout << rev << endl;
    return 0;
}
