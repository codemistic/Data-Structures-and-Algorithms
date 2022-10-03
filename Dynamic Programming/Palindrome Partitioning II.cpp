bool isPalin(string &s, int start, int end) 
    { 
        while(start<end) 
        { 
            if(s[start++]!=s[end--]) 
                return 0; 
        }   
        return 1; 
    }
    int dp[2001][2001];
    int minCutFrom(string s,int start, int end){
        if(start==end || isPalin(s,start,end))
            return 0; //no cut needed
        
        if(dp[start][end]!=-1)return dp[start][end];
        int minCut=s.size()-1;
        for(int i=start;i<=end;i++){
            if(isPalin(s,start,i)){
                minCut=min(minCut, 1+minCutFrom(s,i+1,end));
            }
        }
        return dp[start][end]=minCut;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return minCutFrom(s,0,s.length()-1);
    }
