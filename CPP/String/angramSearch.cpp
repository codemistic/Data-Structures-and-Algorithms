#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;

bool isSame(int a[], int b[])
{
    for (int i = 0; i < CHAR; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool anagramSeach(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();
    int ct[CHAR] = {0};
    int cp[CHAR] = {0};
    for (int i = 0; i < m; i++)
    {
        ct[txt[i]]++;
        cp[pat[i]]++;
    }
    if (m == n)
        return isSame(ct, cp);
    for (int i = m; i < n; i++)
    {
        if (isSame(ct, cp))
            return true;
        ct[txt[i]]++;
        ct[txt[i - m]]--;
    }
    return false;
}

int main()
{
    string s, k;
    cin >> s >> k;
    cout << anagramSeach(s, k);
    return 0;
}