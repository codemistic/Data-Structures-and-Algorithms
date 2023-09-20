public int[] runningSum(int[] nums) {
    Arrays.parallelPrefix(nums, Integer::sum);
    return nums;
}

