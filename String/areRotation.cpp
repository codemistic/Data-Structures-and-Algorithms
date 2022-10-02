#include <bits/stdc++.h>
using namespace std;

bool areRotated(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    return (s1 + s1).find(s2) != string::npos;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << areRotated(s1, s2);
    return 0;
}