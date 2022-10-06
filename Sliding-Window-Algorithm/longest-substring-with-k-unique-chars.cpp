#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int getLengthSubstring(string S, int k)
{
    int n = S.size(), i = 0, j = 0, count = 0, maxLength = -1;
    map<char, int> fz;
    while (j < n)
    {
        //calculations
        fz[S[j]]++;
        if (fz[S[j]] == 1)
            count++;

        if (count < k)
            j++;
        else if (count == k)
        {
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        else
        {
            while (count > k)
            {
                fz[S[i]]--;
                if (fz[S[i]] == 0)
                    count--;
                i++;
            }
            j++;
        }
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
        int k;
        cin >> k;
        cout << getLengthSubstring(S, k) << "\n";
        T--;
    }
    return 0;
}