class Solution {
public:  
    int numDecodings(string s) {
        if(s[0] == '0')return 0;
        int n = s.length();
        vector<int> dp(n+2,0);
        dp[n+1] = 1;
        dp[n] = 1;
        for(int i = n-1; i >= 0; i--){
            int ans = 0;   
            int num = s[i] - '0';
            if(num > 0)ans += dp[i+1];
            if(i+1 < s.length() && num > 0){
                num = num*10+(s[i+1] - '0');
                if(num > 0 && num <= 26)ans += dp[i+2];
            }
            dp[i] = ans;
        }
        return dp[0];        
    }
};
