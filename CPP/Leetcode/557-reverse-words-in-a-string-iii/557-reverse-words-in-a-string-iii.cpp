class Solution {
public:
    string reverseWords(string s) {
        string k="";
        string res="";
        for(int i=0;i<s.length();i++)
        {   
            if(s[i]!=' ') k=k+s[i];
            if(s[i]==' ' || i+1==s.length())
            {
                reverse(k.begin(),k.end());
                    res=res+k+" ";
                k="";
            }
        }
        return res.substr(0,res.length()-1);
        
    }
};