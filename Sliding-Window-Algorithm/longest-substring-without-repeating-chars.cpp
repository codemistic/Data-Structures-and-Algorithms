#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int getLengthSubstring(string S)
{
    int n = S.size(), i = 0, j = 0, maxLength = 1;
    unordered_map<char, int> fz;

    while (j < n)
    {
        fz[S[j]]++;

        if (fz[S[j]] == 1)
            maxLength = max(maxLength, j - i + 1);
        else if (fz[S[j]] == 2)
            while (fz[S[j]] != 1)
            {
                fz[S[i]]--;
                i++;
            }
        j++;
    }

    return maxLength;
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        string S;
        cin >> S;
        cout << getLengthSubstring(S) << "\n";
        T--;
    }
    return 0;
}