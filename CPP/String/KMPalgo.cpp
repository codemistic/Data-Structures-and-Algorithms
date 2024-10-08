#include <bits/stdc++.h>
using namespace std;

void fillLPS(string s, int lps[])
{
    int n = s.length();
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

void KMP(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    fillLPS(pat, lps);

    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << (i - m) << " ";
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    string txt, pat;
    cin >> txt >> pat;
    KMP(txt, pat);
    return 0;
}