class Solution {
public:
    string sortSentence(string s) {
        vector<pair<char,string>> v;
        string k="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='1' && s[i]<='9')
            {
                v.push_back({s[i],k});
                k="";
                i++;
            }
            else k=k+s[i];
        }
        sort(v.begin(),v.end());
        string s1="";
        for(int i=0;i<v.size();i++)
        {
            s1=s1+v[i].second;
            if(i!=v.size()-1)s1+=" ";
        }
        return s1;
        
    }
};