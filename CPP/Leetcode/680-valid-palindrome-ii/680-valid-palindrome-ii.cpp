class Solution {
    private:
    bool pal(string s,int l,int r)
    {
         while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
            
        }    
        return true;

    }
    
public:
    bool validPalindrome(string s) {
        int n=s.length();
        int l=0;
        int r=n-1;
        int f=0;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return pal(s,l+1,r) || pal(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;

       
        
    }
};