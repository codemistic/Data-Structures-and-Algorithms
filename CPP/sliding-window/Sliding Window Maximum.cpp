class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> maxi(k);
        vector<int> ans;
        
        for(int i = 0; i < k; i++) {

            while(!maxi.empty() && nums[maxi.back()] <= nums[i]) {
                maxi.pop_back();
            }
            maxi.push_back(i);
        }
        ans.push_back(nums[maxi.front()]);
        
        for(int i = k; i < nums.size(); i++) {

            //removal
            while(!maxi.empty() && i-maxi.front() >= k) {
                maxi.pop_front();
            }
            
            //addition
            while(!maxi.empty() && nums[maxi.back()] <= nums[i]) {
                maxi.pop_back();
            }

            maxi.push_back(i);

            ans.push_back(nums[maxi.front()]);
        }
        return ans;
    }
};
