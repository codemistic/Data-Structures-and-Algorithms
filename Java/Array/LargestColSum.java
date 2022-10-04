//Find largest colum sum


package Two_Dimensional_Array;
import java.util.Scanner;
public class LargestColSum {
    public static int largestcolsum(int [] [] arr2) {
        int rows = arr2.length;
        int cols = arr2[0].length;
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < cols; i++) {
            int sum = 0;
            for (int j = 0; j < rows; j++) {
                sum = sum + arr2[j][i];
            }
            if ( sum > max) {
                max = sum;
            }
        }
        return max;
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
                System.out.println("Enter the element at " + i + " th row and " + j + " th columns.");
                arr2[i][j] = sc.nextInt();
            }
        }
        return arr2;
    }
    public static void main(String[] args) {
        int [] [] arr2 = takeInput();
        int n = largestcolsum(arr2);
        System.out.println("Largest column sum is " + n);

    }
}
