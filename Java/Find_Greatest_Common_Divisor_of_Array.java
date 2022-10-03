/*
 
LEETCODE QUESTION : 1979. Find Greatest Common Divisor of Array

=> Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
    The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
 */

//The code
class Find_Greatest_Common_Divisor_of_Array {
    public int findGCD(int[] nums) {
        insertion(nums);

        int large = nums[nums.length - 1];
        int small = nums[0];

        int rem = large % small;

        if (rem == 0) {
            return small;
        } else
            return gcd(small, large);

    }

    static int gcd(int a, int b) {
        int result = Math.min(a, b); // Find Minimum of a and b
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }
        return result; // return gcd of a and b
    }

    private void insertion(int arr[]) {

        for (int i = 0; i < arr.length - 1; i++) {

            for (int j = i + 1; j > 0; j--) {

                if (arr[j] < arr[j - 1]) {
                    // swap
                    swaparray(arr, j, j - 1);
                } else {
                    break;
                }
            }
        }
    }

    static void swaparray(int[] arr, int first, int second) {

        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;

    }

}