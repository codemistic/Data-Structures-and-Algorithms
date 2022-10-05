class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string k="";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0;i<n;i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) k+=s[i];
        }
        
        n=k.length();
        int l=0;
        int r=n-1;
        while(l<r)   
        {
            if(k[l]!=k[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};