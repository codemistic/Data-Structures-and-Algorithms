// Arrange Numbers In Array 
// You have been given an empty array(ARR)and its size N.The only input taken from the user will be N and you need not worry about the array.
// Your task is to populate the array using the integer values in the range 1 to N(both inclusive)in the order-1,3,5,.......,6,4,2. 

// Note:You need not print the array.You only need to populate it.

// Input Format:
// The first line contains an Integer't'which denotes the number of test cases or queries to be run.Then the test cases follow.

// The first and the only line of each test case or query contains an integer'N'.

// Output Format:
// For each test case,print the elements of the array/list separated by a single space.

// Output for every test case will be printed in a separate line.

// Constraints:
// 1<=t<=10^2 
// 0<=N<=10^4
// Time Limit:1 sec 

// Sample Input 1:
// 1 6 
// Sample Output 1:
// 1 3 5 6 4 2 
// Explanation of Sample Input 1:
// Since the value of N is 6,the number will be stored in the array in such a fashion that 1 will appear at 0 th index,then 2 at the last index,in a similar fashion 3 is stored at index 1. Hence the array becomes 1 3 5 6 4 2. 
// Sample Input 2:
// 2 
// 9 
// 3 
// Sample Output 2:
// 1 3 5 7 9 8 6 4 2 
// 1 3 2


package Array;
import java.util.Scanner;

public class Arrange_Number_In_Array {
    public static void printArray(int[] arr1) {
        int n = arr1.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr1[i]);
        }
    }

    public static int[] arrangeNumbers(int[] arr, int x) {

        int right = x - 1;
        int left = 0;
        int i = 1;

        while (left <= right) {
            if (i % 2 != 0) {
                arr[left] = i;
                i += 1;
                left += 1;
            } else {
                arr[right] = i;
                i += 1;
                right--;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] arr1 = arrangeNumbers(arr, n);
        printArray(arr1);

    }
}
