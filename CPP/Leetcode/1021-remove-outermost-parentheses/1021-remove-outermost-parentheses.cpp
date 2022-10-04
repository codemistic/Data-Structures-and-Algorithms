class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string k="";
        for(int i=0;i<s.length();i++)
        {
            if(cnt==0 && s[i]=='(') {cnt++;continue;}
            if(s[i]=='(') cnt++;
            if(s[i]==')') cnt--;
            if(cnt==0 && s[i]==')') {continue;}
            
            k=k+s[i];
        }
        return k;
    }
};