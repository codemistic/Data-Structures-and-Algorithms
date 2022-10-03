//https://leetcode.com/problems/plus-one/
//☝️Problem Link☝️

class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for(int i = n - 1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        int[] newNumb = new int[n + 1];
        newNumb[0] = 1;
        return newNumb;
    }
}
