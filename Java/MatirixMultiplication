import java.util.Scanner;
import java.lang.*;

public class MatrixMultiplication
{
	public static void main(String args[]) 
	{
		int r1, r2, c1, c2;
		
		Scanner input = new Scanner(System.in);
		System.out.println("Enter matrix 1 order: ");
		r1 = input.nextInt();
		c1 = input.nextInt();
		
		System.out.println("Enter matrix 2 order: ");
		r2 = input.nextInt();
		c2 = input.nextInt();
		
		if(r1 != c2){
			System.out.println("Matrix Order doesn't match, exiting..");
			System.exit(1);
		}
		
		
		int mat1[][] = new int[r1][c1];
		int mat2[][] = new int[r2][c2];
		int out[][] = new int[r1][c2];
		
		System.out.println("Enter matrix 1 elements: ");
		for(int i=0; i<r1; i++) {
			for(int j=0; j<c1; j++) {
				mat1[i][j] = input.nextInt();
			}
		}
		
		System.out.println("Enter matrix 1 elements: ");
		for(int i=0; i<r2; i++) {
			for(int j=0; j<c2; j++) {
				mat2[i][j] = input.nextInt();
			}
		}
		
		
		System.out.println();
		System.out.println("Final matrix: ");
		for(int i=0;i<r1;i++){  
			for(int j=0;j<c2;j++){  	
				out[i][j]=0;    
				for(int k=0;k<r2;k++)    
				{	    
					out[i][j]+=mat1[i][k]*mat2[k][j];    
				}
				System.out.print(out[i][j]+" ");  
			}
			System.out.println();
		}
		
		
	}
}
