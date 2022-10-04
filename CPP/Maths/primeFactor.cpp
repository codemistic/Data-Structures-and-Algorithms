#include <bits/stdc++.h>
using namespace std;

void PrimeFactor(int n)
{
    if (n == 1)
        return;

    int i = 2;
    while (n % i == 0)
    {
        cout << i << ' ';
        n = n / i;
    }

    i = 3;
    while (n % i == 0)
    {
        cout << i << ' ';
        n = n / i;
    }

    for (int i = 5; i * i <= n; i = i + 6)
    {
        while (n % i == 0)
        {
            cout << i << ' ';
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            cout << i + 2 << ' ';
            n = n / (i + 2);
        }
    }
    if (n > 3)
        cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    PrimeFactor(n);

    return 0;
}