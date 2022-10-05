import java.util.Arrays;
import java.util.Scanner;

public class CountSort {

	public static void main(String[] args) {

//		This algorithm is preferred for single digit number
		System.out.println("Counting Sort : ");

		System.out.print("Enter the size of array : ");
		try (Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			int a[] = new int[n];

			System.out.println("Enter elements : ");
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
			}

			System.out.println("Array before sorting : " + Arrays.toString(a));

			countSort(a); // calling the function

			System.out.println("\nArray after sorting : " + Arrays.toString(a));
		}

//		Time Complexity : O(n+k+n+n) = O(n+k) 
//		if we consider k as content then O(n) -> Linear Time :)
//		Space Complexity : O(n+k)
	}

	private static void countSort(int a[]) {
		int k = getMax(a); // to get maximum element for making count array

		int count[] = new int[k + 1]; // to fill frequency of element
		for (int i = 0; i < a.length; i++) {
			count[a[i]]++;
		}

//		to reflect position in count array
//		similar to filling cumulative frequency 
		for (int i = 1; i <= k; i++) {
			count[i] = count[i] + count[i - 1];
		}

		// to put element at it's correct position
		int b[] = new int[a.length];
		for (int i = b.length - 1; i >= 0; i--) {
			b[--count[a[i]]] = a[i];
		}

		// copying elements to a
		for (int i = 0; i < a.length; i++)
			a[i] = b[i];
	}

	private static int getMax(int[] a) {
		int max = Integer.MIN_VALUE;
		for (int i : a) {
			if (i > max)
				max = i;
		}
		return max;
	}
}