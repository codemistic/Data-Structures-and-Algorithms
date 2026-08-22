class Solution {
public:
vector<int>a,t;
    Solution(vector<int>& nums) {
      a=nums;
      t=nums;
    }
    
    vector<int> reset() {
        return t;
    }
    
    vector<int> shuffle() {
        prev_permutation(a.begin(),a.end());
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */