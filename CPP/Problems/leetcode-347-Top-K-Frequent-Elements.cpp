class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //top k frequent elements 
        //given an integer array nums and an integer k,return the k most frequent elements.
        //can be done using priority queue
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]++;
        priority_queue<pair<int,int>> pq;
        for(auto x:m)
            pq.push({x.second,x.first});
        vector<int> ans;
        while(k>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};