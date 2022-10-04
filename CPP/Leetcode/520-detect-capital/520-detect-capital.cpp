class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        int n=word.length();
        for(int i=0;i<n;i++)
        {
            if(isupper(word[i])) cnt++;
        }
        if(cnt==n || cnt==0) return true;
        if(cnt==1 && isupper(word[0])) return true;
        return false;
    }
};