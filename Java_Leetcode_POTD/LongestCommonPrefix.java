class  LongestCommonPrefix {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Set<Integer> set = new HashSet<>();
        int maxLen = 0;
        for(int num : arr1){
            set.add(num);
            while(num != 0){
                num /= 10;
                set.add(num);
            }
        }

        for(int num : arr2){
            while(num > 0){
                if (set.contains(num)) {
                    maxLen = Math.max(maxLen,String.valueOf(num).length());
                }

                num /= 10;
            }
        }

        return maxLen;

    }
}