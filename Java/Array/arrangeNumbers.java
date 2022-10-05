import java.util.*;
public class arrange_numbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner (System.in);
        int n = sc.nextInt ();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt ();
        int p1 = 0, p2 = n - 1;

        while (p1 < p2)
        {
            while (arr[p1] % 2 == 0 && p1 < p2)
                p1++;
        
            while (arr[p2] % 2 != 0 && p1 < p2)
                p2--;
 
            if (p1 < p2)
	        {
                int temp = arr[p1]; 
                arr[p1] = arr[p2];
                arr[p2] = temp;
                p1++;
                p2--;
            }
        } 
        
        for (int i = 0; i < n; i++)
            System.out.print (arr[i] + " ");
	}

}
