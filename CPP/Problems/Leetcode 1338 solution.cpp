class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<pair<int,int>> ans;
        unordered_map<int,int> m;
        for(auto x:arr)
            m[x]++;
        for(auto x:m)
            ans.push_back({x.second,x.first});
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        int fans=0,temp=0,n=arr.size()/2;
        for(int i=0;i<ans.size();i++)
        {
            temp+=ans[i].first;
            fans++;
            if(temp>=n)
                return fans;
        }
        return 0;
    }
};
