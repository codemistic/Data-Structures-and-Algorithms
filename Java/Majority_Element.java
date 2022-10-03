/*
 *  Question:
 *  Given an array nums of size n, return the majority element.
 *  The majority element is the element that appears more than ⌊n / 2⌋ times.
 *  
 *  I have solved this question and even optimised it using the famous Algorithm known as 
 *          "Moore's Voting Algorithm"
 * 
 *  LeetCode Q - 169
 * 
 * 
 *  Time Complexity  - O(N)
 *  Space Complexity - O(1)
 */

public class Majority_Element {
    public static void main(String[] args) {
        int arr[] = { 2, 2, 1, 1, 1, 2, 2 };
        System.out.println(majority(arr));
    }

    public static int majority(int nums[]) {
        int c = 0, elm = 0;
        for (int i = 0; i < nums.length; i++) {
            if (c == 0)
                elm = nums[i];
            if (elm == nums[i])
                c++;
            else
                c--;
        }
        return elm;
    }
}
