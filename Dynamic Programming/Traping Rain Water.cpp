// 42. Trapping Rain Water (Leetcode)
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int>leftHeight(n, -1), rightHeight(n, -1);
        int ans = 0;
        
        for (int i = 1; i < n; i++)
        {
            leftHeight[i] = max(leftHeight[i - 1], height[i - 1]);
            rightHeight[n - i - 1] = max(rightHeight[n - i], height[n - i]);
        }
        
        for (int i = 1; i < n; i++)
        {
            int x = min(leftHeight[i], rightHeight[i]) - height [i];
            if (x > 0)
            {
                ans += x;
            }
        }
        
        return ans;
    }
};