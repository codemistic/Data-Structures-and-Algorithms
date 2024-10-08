class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum, min = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int l = i + 1, r = nums.size() - 1;
                while (l < r) {
                    int nsum = nums[r] + nums[l] + nums[i];
                    if (nsum == target)
                        return nsum;
                    else if (nsum < target)
                        l++;
                    else
                        r--;
                    if (abs(nsum - target) < min) {
                        sum = nsum;
                        min = abs(sum - target);
                    }
                }
            }
        }
        return sum;
    }
};
