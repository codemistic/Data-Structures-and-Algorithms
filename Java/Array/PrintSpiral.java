// Print Spiral

// For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
// a. First row(left to right)
// b. Last column(top to bottom)
// c. Last row(right to left)
// d. First column(bottom to top)
//  Mind that every element will be printed only once.


// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

// Second line onwards, the next 'N' lines or rows represent the ith row values.

// Each of the ith row constitutes 'M' column values separated by a single space.
// Output format :
// For each test case, print the elements of the two-dimensional array/list in the spiral form in a single line, separated by a single space.

// Output for every test case will be printed in a seperate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// 0 <= M <= 10^3
// Time Limit: 1sec
// Sample Input 1:
// 1
// 4 4 
// 1 2 3 4 
// 5 6 7 8 
// 9 10 11 12 
// 13 14 15 16
// Sample Output 1:
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
// Sample Input 2:
// 2
// 3 3 
// 1 2 3 
// 4 5 6 
// 7 8 9
// 3 1
// 10
// 20
// 30
// Sample Output 2:
// 1 2 3 6 9 8 7 4 5 
// 10 20 30 







package Two_Dimensional_Array;
import java.util.Scanner;
public class PrintSpiral {
    public static void spiral(int [] [] arr) {
        int currRow = 0;
        int currCol = 0;
        int rows = arr.length;
        int cols = arr[0].length;
        int count = 0;
        int totalelements = rows * cols;
        while (count < totalelements) {
            for (int i = currCol; i < cols; i++) {
                System.out.print(arr[currRow][i] + " ");
                count++;
            }
            currRow++;
            for (int i = currRow; i < rows; i++) {
                System.out.print(arr[i][cols - 1] + " ");
                count++;
            }
            cols--;
            for (int i = cols - 1; i >= currCol; i--) {
                System.out.print(arr[rows - 1][i] + " ");
                count++;
            }
            rows--;
            for (int i = rows - 1; i >= currRow ; i--) {
                System.out.print(arr[i][currCol] + " ");
                count++;
            }
            currCol++;
        }

    }

    public static int [] [] takeInput() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows: ");
        int rows = sc.nextInt();
        System.out.println("Enter the number of colums: ");
        int cols = sc.nextInt();
        int [][] arr2 = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr2[i][j] = sc.nextInt();
            }
        }
        return arr2;
    }
    public static void main(String[] args) {
        int [] [] arr2 = takeInput();
        spiral(arr2);

    }
}
