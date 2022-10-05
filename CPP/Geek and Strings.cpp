class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        unordered_map<string,int> mp;
        
        for(int i=0;i<N;i++)
        {
            string s ="";
            for(int j=0;j<li[i].size();j++)
            {
                s +=li[i][j];
                mp[s]+=1;
            }
        }
        vector<int> ans(Q, 0);
        for(int i=0;i<Q;i++)
        {
            ans[i] = mp[query[i]];
        }
        
        return ans;
    }
};
