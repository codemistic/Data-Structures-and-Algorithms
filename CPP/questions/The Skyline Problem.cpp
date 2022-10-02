class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>>pq;
        vector<int> co;
        
        for(auto b:buildings){
            co.push_back(b[0]);
            co.push_back(b[1]);
        }
        
        sort(co.begin(), co.end());
        
        int n=unique(co.begin(), co.end())-co.begin();
        int j=0;
        int preHei=0;
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
        while(j<buildings.size() && buildings[j][0]<=co[i])
        pq.push(make_pair(buildings[j][2], buildings[j][1])), j++;
        while(!pq.empty() && pq.top().second<=co[i])  pq.pop();
        int nowHei=pq.empty()?0:pq.top().first;
        
        if(nowHei!=preHei){
            res.push_back({co[i], nowHei});
            preHei=nowHei;
        }
        }
        return res;
        
    }
};
