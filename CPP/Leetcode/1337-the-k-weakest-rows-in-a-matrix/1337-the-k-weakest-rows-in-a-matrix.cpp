class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        set<pair<int,int>> s;
        for(int i=0;i<n;i++)
        {
            int cnt = count(mat[i].begin(),mat[i].end(),1);
            s.insert({cnt,i});
        }
        vector<int> v;
        for(auto x:s)
        {
            if(k==0) break;
            v.push_back(x.second);
            k--;
        }
        return v;
        
    }
};