//  Find Unique element in the array

// You have been given an integer array/list(ARR)of size N.Where N is equal to[2 M+1].
// Now,in the given array/list,'M'numbers are present twice and one number is present only once.
// You need to find and return that number which is unique in the array/list.

// Note:Unique element is always present in the array/list according to the given condition.

// Input format:
// The first line contains an Integer't'which denotes the number of test cases or queries to be run.Then the test cases follow.
// First line of each test case or query contains an integer'N'representing the size of the array/list.
// Second line contains'N'single space separated integers representing the elements in the array/list.

// Output Format:
// For each test case,print the unique element present in the array.
// Output for every test case will be printed in a separate line.

// Constraints:
// 1<=t<=10^2 
// 0<=N<=10^3 
// Time Limit:1 sec

// Sample Input 1:
// 1 
// 7 
// 2 3 1 6 3 6 2 
// Sample Output 1:1

// Sample Input 2:
// 2 
// 5 
// 2 4 7 2 7 
// 9 
// 1 3 1 3 6 6 7 10 7 
// Sample Output 2:
// 4 
// 10







package Array;
import java.util.Scanner;

public class Unique_Element {

    public static int uniqueElement(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {

            int j = 0;
            for (; j < n; j++) {
                if (j != i) {
                    if (arr[i] == arr[j]) {
                        break;
                    }
                }

            }
            if (j == arr.length) {
                return arr[i];
            }

        }
        return Integer.MIN_VALUE;
    }

    public static int[] takingInput() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = takingInput();
        int n = uniqueElement(arr);
        System.out.println(n);
    }
}
