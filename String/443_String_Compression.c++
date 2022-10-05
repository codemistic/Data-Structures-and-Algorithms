// Name :String Compression
// Url: https://leetcode.com/problems/string-compression/
// Tag : String

class Solution
{
public:
    int compress(vector<char> &chars)
    {

        char temp = chars[0];
        int cnt = 0, n = chars.size();
        for (int i = 0; i < n; i++)
        {
            if (chars[i] == temp)
                cnt++;
            else
            {
                chars.erase(chars.begin(), chars.begin() + i);
                i = 0;
                n -= cnt;
                chars.push_back(temp);
                if (cnt != 1)
                {
                    string k = to_string(cnt);
                    for (auto x : k)
                        chars.push_back(x);
                }
                temp = chars[i];
                cnt = 1;
                continue;
            }
        }
        chars.erase(chars.begin(), chars.begin() + cnt);
        chars.push_back(temp);
        if (cnt != 1)
        {
            string k = to_string(cnt);
            for (auto x : k)
                chars.push_back(x);
        }
        return chars.size();
    }
};