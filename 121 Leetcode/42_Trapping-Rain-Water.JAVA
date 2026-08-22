// Name:- Ayushi Tiwari
// Date:- 06 October 2022

/*
PROBLEM STATEMENT
LEETCODE - 42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Intuition: We need a minimum of leftMax and rightMax.So if we take the case when height[l]<=height[r] we increase l++, 
so we can surely say that there is a block with a height more than height[l] to the right of l.
And for the same reason when height[r]<=height[l] we can surely say that there is a block to the left of r which is at least of height[r]. 
So by traversing these cases and using two pointers approach the time complexity can be decreased without using extra space.
*/

class Solution {
    public int trap(int[] height) {

        int n = height.length;
        int left = 0, right = n - 1;
        int leftmax = 0, rightmax = 0;
        int res = 0;

        while (left <= right) {
            //iterate from left to right
            if (height[left] <= height[right]) {
                if (height[left] >= leftmax) leftmax = height[left];
                else res += leftmax - height[left];
                left++;
            } else {
                if (height[right] >= rightmax) rightmax = height[right];
                else res += rightmax - height[right];
                right--;
            }

        }
        return res;
    }
}

/*Time Complexity: O(N) because we are using 2 pointer approach.
Space Complexity: O(1) because we are not using anything extra.*/
