// Selection Sort

// Provided with a random integer array/list(ARR) of size N, you have been required to sort this array using 'Selection Sort'.
//  Note:
// Change in the input array/list itself. You don't need to return or print the elements.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.
// Output format :
// For each test case, print the elements of the array/list in sorted order separated by a single space.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 2 13 4 1 3 6 28
// Sample Output 1:
// 1 2 3 4 6 13 28
// Sample Input 2:
// 2
// 5
// 9 3 6 2 0
// 4
// 4 3 2 1
// Sample Output 2:
// 0 2 3 6 9
// 1 2 3 4




package Array;
import java.util.Scanner;

public class SelectionSort {

    public static void printArray(int [] arr) {
        System.out.print("The sorted array is: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }

    public static int [] selectionSort(int [] arr) {
        int n = arr.length;
        int i = 0;
        for (; i < n - 1; i++) {
            int min = Integer.MAX_VALUE;
            int minIndex = -1;

            for (int j = i; j < n; j++) {
                if ( arr[j] < min) {
                    min = arr[j];
                    minIndex = j;
                }
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
        return arr;
    }

    public static int [] takeInput(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of the array: ");
        int n = sc.nextInt();
        int [] arr = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        return arr;
    }

    public static void main(String[] args) {

        int [] arr = takeInput();
        int [] arr2 = selectionSort(arr);
        printArray(arr2);
    }
}
