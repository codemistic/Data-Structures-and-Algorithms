#include<iostream>
using namespace std;

//This program prints the number of zeros in a factorial.

int countZero(int n)
{
    int res = 0;
    for(int i = 5;i<=n;i = i*5)
    {
        res = res + n/i;
    }
    return res;
}


int main()
{

    int n;
    cin>>n;

    cout<<countZero(n)<<endl;
}