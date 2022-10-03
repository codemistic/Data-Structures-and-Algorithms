#include <bits/stdc++.h>
using namespace std;

int perfectnumber(int n)
{
    int sum=0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}

int main()
{
    int n;
    cout<<"Enter a number to check whether it is a perfect number or not: ";
    cin >> n;
    if (perfectnumber(n) == n)
        cout << n << " is a perfect number." << endl;
    else
        cout << n << " is not a perfect number." << endl;
    return 0;
}