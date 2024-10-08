/*Problem You are given an array A=[A1 ,A2 ​ ,…,AN ​ ] consisting of N positive integers. You are also given a constant K, using which you can perform the following operation on AA: Choose two distinct indices ii and jj such that A_i ​ +A_j ​ ≤K, and remove either A_iA i ​ or A_jA j ​ from AA. Is it possible to obtain an array consisting of only one element using several (possibly, zero) such operations?
Input Format The first line of input contains a single integer TT, denoting the number of test cases. The description of T test cases follows. The first line of each test case contains two space-separated integers NN and K. The second line contains N space-separated integers 1 ​ ,A 2 ​ ,…,A N ​ .
 Output Format For each test case, print "YES" if it is possible to obtain an array consisting of only one element using the given operation, otherwise print "NO". You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        for (int i = 0; i < n; i++)
        {
            int e;
            cin >> e;
            v.pb(e);
        }
        if (n == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            sort(v.begin(), v.end());
            ll maxi = *max_element(v.begin(), v.end());
            ll mini = *min_element(v.begin(), v.end());
            if (maxi + mini <= k)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}