//Find largest row sum






package Two_Dimensional_Array;
import java.util.Scanner;
public class Largest_Row_Sum {
    public static int largestcolsum(int [] [] arr2) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < arr2.length; i++) {
            int sum = 0;
            for (int j = 0; j < arr2[i].length; j++) {
                sum = sum + arr2[i][j];
            }
            if( sum > max) {
                max = sum;
            }
        }
        return max;
    }
    public static int [] [] takingInput() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows: ");
        int rows = sc.nextInt();
        System.out.println("Enter the number of columns: ");
        int cols = sc.nextInt();
        int [] [] arr = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.println("Enter the element at " + i + " rows " + j + " columns: ");
                arr[i][j] = sc.nextInt();
            }
        }
        return arr;
    }
    public static void main(String[] args) {
        int [] [] arr2 = takingInput();
        int n = largestcolsum(arr2);
        System.out.println(n);
    }
}
