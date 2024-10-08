class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            m2[t[i]]++;
        }
        char cnt='a';
        for(int i=0;i<t.length();i++)
        {
            if(m1[t[i]]!=m2[t[i]]) {cnt=t[i];break;}
        }
        return cnt;
        
    }
};