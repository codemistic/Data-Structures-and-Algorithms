#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    int search(string pat, string txt)
    {
        int countAnagram = 0, i = 0, j = 0, k = pat.size(), countFz = 0, n = txt.size();
        map<char, int> fz;

        for (int i = 0; i < k; i++)
        {
            fz[pat[i]]++;
            if (fz[pat[i]] == 1)
                countFz++;
        }

        while (j < n)
        {
            // calculation
            if (fz.find(txt[j]) != fz.end())
            {
                fz[txt[j]]--;
                if (fz[txt[j]] == 0)
                    countFz--;
            }

            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                // get ans
                if (countFz == 0)
                    countAnagram++;
                // slide
                if (fz.find(txt[i]) != fz.end())
                {
                    fz[txt[i]]++;
                    if (fz[txt[i]] == 1)
                        countFz++;
                }
                i++;
                j++;
            }
        }
        return countAnagram;
    }
};