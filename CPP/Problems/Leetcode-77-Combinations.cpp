class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        generateCombinations(1,n,result,curr,k);
        return result;
    }
    
    void generateCombinations(int start, int n, vector<vector<int>>& result, vector<int> &curr,int k){
        if(curr.size() == k){
            result.push_back(curr);
            return;
        }
        
        for(int i = start ; i <= n ; i++)
        {
            curr.push_back(i);
            generateCombinations(i+1, n, result,curr,k);
            curr.pop_back();
        }
    }
};