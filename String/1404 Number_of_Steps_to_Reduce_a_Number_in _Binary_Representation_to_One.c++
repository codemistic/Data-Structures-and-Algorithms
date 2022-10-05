// Name: Number_of_Steps_to_Reduce_a_Number_in _Binary_Representation_to_One
// Url: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
//-----------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int numSteps(string s)
    {
        int cnt = 0, cntz = 0;

        for (int i = s.length() - 1; i > 0; i--)
        {
            if (s[i] == '0' && cntz == 0)
                cnt++;
            else if (s[i] == '0')
                cnt += 2;
            else
            {
                cntz++;
                cnt++;
            };
        }
        if (cntz > 0)
            cnt += 2;
        return cnt;
    }
};