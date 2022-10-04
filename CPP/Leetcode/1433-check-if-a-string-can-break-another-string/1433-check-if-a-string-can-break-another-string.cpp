class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int f=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]>=s2[i]) continue;
            else
            {
                f=1;
            }
        }
        int g=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s2[i]>=s1[i]) continue;
            else
            {
                g=1;
            }
        }
        if(f==0 || g==0) return true;
        else return false;
    }
};