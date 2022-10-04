class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int n=word1.length();
        int m=word2.length();
        int i=0;
        for(i=0;i<min(n,m);i++)
        {
            ans+=word1[i];
            ans+=word2[i];
        }
        if(i==n)
        {
            for(i;i<m;i++)
            {
                ans+=word2[i];
            }
        }
        if(i==m)
        {
            for(i;i<n;i++)
            {
                ans+=word1[i];
            }
        }
        return ans;
        
    }
};