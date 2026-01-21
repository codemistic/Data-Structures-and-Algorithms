// Name: Ransom Note
// Url : https://leetcode.com/problems/ransom-note/
// Leetcode Problem No: 383

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> v(26, 0), v1(26, 0);
        for (auto x : ransomNote)
            v[x - 'a']++;
        for (auto x : magazine)
            v1[x - 'a']++;
        for (int i = 0; i < 26; i++)
            if (v1[i] < v[i])
                return 0;
        return 1;
    }
};