class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length();
        int m=t.length();
        int cnt=0;
        string a="",b="";
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='#') cnt++;
            else
            {
                if(cnt==0)
                {
                    a=a+s[i];
                }
                else cnt--;
            }
        }
        cnt=0;
        for(int i=m-1;i>=0;i--)
        {
            if(t[i]=='#') cnt++;
            else
            {
                if(cnt==0)
                {
                    b=b+t[i];
                }
                else cnt--;
            }
        }
        if(a==b) return true;
        else return false;
    
        
    }
};