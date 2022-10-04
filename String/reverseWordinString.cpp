#include <iostream>
using namespace std;
string reverseWords(string s)
{
    int n = s.length();
    if (n == 1)
    {
        return s;
    }
    int k = 0, j;
    for (int i = 0; i < n; i++)
    {
        if (s[i + 1] == 32 || s[i + 1] == '\0')
        {
            j = i;
            char p;
            while (k < j)
            {
                p = s[k];
                s[k] = s[j];
                s[j] = p;
                k++, j--;
            }
            k = i + 2;
        }
    }
    return s;
}

int main()
{
    string s,k;
    cout << "Enter The String : ";
    getline(cin, s);
    k=reverseWords(s);
    cout << s << endl;
    cout << k << endl;
}