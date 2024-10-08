class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(i==0) cnt=mp[s[i]];
            else
            {
                if(cnt!=mp[s[i]]) return false;
            }
        }
        return true;
    }
};