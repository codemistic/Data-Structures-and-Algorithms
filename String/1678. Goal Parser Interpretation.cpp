// Name: Goal Parser Interpretation
// Url : https://leetcode.com/problems/goal-parser-interpretation/
// Leetcode Problem No: 1678.

class Solution
{
public:
    string interpret(string s)
    {
        int n = s.length();
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' && s[i + 1] == ')')
            {
                res += 'o';
                i++;
            }
            else if (s[i] == '(' && s[i + 1] == 'a')
            {
                res += "al";
                i += 3;
            }
            else
                res += s[i];
        }
        return res;
    }
};