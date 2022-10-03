#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    return (log10(n) + 1);
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
    }
    else
    {
        n = abs(n);
        cout << countDigits(n);
    }

    return 0;
}