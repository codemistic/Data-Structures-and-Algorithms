class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        findCombinations(candidates,target,0,ds);
        return result;
    }
    
    void findCombinations(vector<int>&candidates, int target, int i,vector<int>ds){
        
        if(target == 0)
        {
            result.push_back(ds);
            return;
        }
        if(i == candidates.size())
        {
            return;
        }
        if(target >= 0)
        {
            ds.push_back(candidates[i]);
            target = target - candidates[i];
            findCombinations(candidates, target, i, ds);
            target += candidates[i];
            ds.pop_back();
            findCombinations(candidates, target, i+1 , ds);
            return;
        }
    }
};