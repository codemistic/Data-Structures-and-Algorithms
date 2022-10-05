class Solution {
    public int minMoves2(int[] nums) {
        int mean = 0;
        int ans = 0;
        Arrays.sort(nums);
        mean = nums[nums.length/2];
        for(int num : nums)
            ans+=Math.abs(mean-num);
        return ans;
    }
}