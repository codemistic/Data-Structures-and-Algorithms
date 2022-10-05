/*
   LEETCODE QUESTION : 2169. Count Operations to Obtain Zero
 */

public class CountOperationsToObtainZero {

    public int countOperations(int num1, int num2) {
        return helper(num1, num2, 0);

    }

    private int helper(int num1, int num2, int count) {

        if (num1 == 0 || num2 == 0) {
            return count;
        }
        if (num1 > num2)
            return helper(num1 - num2, num2, count + 1);
        else
            return helper(num1, num2 - num1, count + 1);

    }

}
