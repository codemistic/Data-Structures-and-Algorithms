
// This code is a implementation of Collatz Numbers.
// Problem statement is: https://projecteuler.net/problem=14

// Here we need to find any number which forms longest chain(collatz series) under one million.

// One code if brute force which goes for every number and since longest chain will be arnd 525 time complexity will be: 106 * 500 (approx.)

// Other is kind of Dp-ish approach which stores value of a chain and also update all the numbers appearing in the chain thus taking less time
// Solution is bit recursive and recursion ends where we find any value which is -1.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

ll int collatz(ll int curr, vector<ll int> &vec, ll int lv)
{
    if (curr <= lv && vec[curr] != -1)
    {
        // when we find any number in chain which has a value more than -1, its time to stop
        return vec[curr];
    }
    // collatz basic rule: n even -> (n / 2),  n odd - > 3n +1

    ll int next = (3 * curr) + 1;

    if (curr % 2 == 0)
    {
        next = curr / 2;
    }
    // prev number in range = 1 + next number in range
    // (8 -> 4 -> 2 -> 1)  here  (answer for 8 is 4) and (answer for 4 is 3)
    int nextv = 1 + collatz(next, vec, lv);
    // if number lies in range(0 - vector.size()) then update it , other ignore it
    if (curr <= lv)
    {
        vec[curr] = nextv;
    }
    return nextv;
}

void solve()
{
    int x = 1000000;
    vector<ll int> vec(x + 1, -1);
    vec[0] = vec[1] = 1;
    for (int i = 1; i < x; i++)
    {
        vec[i + 1] = collatz(i + 1, vec, x - 1);
    }
    ll int maxm = -1, ans = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] >= maxm)
        {
            maxm = vec[i];
            ans = i;
        }
        maxm = max(maxm, vec[i]);
    }
    cout << ans << endl;
    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin.exceptions(cin.failbit);

    clock_t start = clock();

    solve();

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    printf("Time measured: %.3f seconds.\n", elapsed);

    return 0;
}
