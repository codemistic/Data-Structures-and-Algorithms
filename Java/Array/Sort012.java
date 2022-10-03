// Sort 0 1 2 

// You are given an integer array/list(ARR)of size N.It contains only 0 s,1 s and 2 s.Write a solution to sort this array/list in a'single scan'.

// 'Single Scan'refers to iterating over the array/list just once or to put it in other words,you will be visiting each element in the array/list just once.

// Note:
// You need to change in the given array/list itself.Hence,no need to return or print anything.

// Input format:
// The first line contains an Integer't'which denotes the number of test cases or queries to be run.Then the test cases follow.

// First line of each test case or query contains an integer'N'representing the size of the array/list.

// Second line contains'N'single space separated integers(all 0 s,1 s and 2 s)representing the elements in the array/list.

// Output Format:
// For each test case,print the sorted array/list elements in a row separated by a single space.

// Output for every test case will be printed in a separate line.

// Constraints:
// 1<=t<=10^2 
// 0<=N<=10^5 
// Time Limit:1 sec 

// Sample Input 1:
// 1 
// 7 
// 0 1 2 0 2 0 1 

// Sample Output 1:
// 0 0 0 1 1 2 2 

// Sample Input 2:
// 2 
// 5
// 2 2 0 1 1 
// 7 
// 0 1 2 0 1 2 0 
// Sample Output 2:
// 0 1 1 2 2 
// 0 0 0 1 1 2 2


package Array;
import java.util.Scanner;

public class Sort012 {

    public static int [] takeInput() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of the array: ");
        int n = sc.nextInt();
        int [] arr = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter the element at " + i + " th index.");
            arr[i] = sc.nextInt();
        }
        return arr;
    }
    public static void swap(int [] arr, int i, int j) {
        // i = number to be swapped.
        // j = number with which it is swapped.

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }


    public static int [] sort012threePointerApproach(int [] arr) {
        int i = 0;
        int j = 0;
        int k = arr.length - 1;

        while (i <= k) {
            if (arr[i] == 1) {
                i++;
            } else if (arr[i] == 0) {
                swap(arr, i, j);
                i++;
                j++;
            } else  {
                swap(arr, i, k);
                k--;
            }
        }
        return arr;
    }

    public static void printArray(int [] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int [] arr = takeInput();
        int [] finalArray = sort012threePointerApproach(arr);
        printArray(finalArray);
    }
}
