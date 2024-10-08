import java.io.IOException;
import java.io.*;
public class Codechef3 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int row = 0; row < n; row++) {
                for (int spaces = n; spaces > row; spaces--) {
                    System.out.print(" ");
                }
                if(row%2!=0){
                    for (int i = 0; i <= row; i++) {
                        if (i%2!=0 || i != 1) {
                            if(i == 0 || i == row){
                                System.out.print("* ");
                            }
                            else{
                                System.out.print("  ");
                            }
                        }
                    }
                }
                else{
                    for (int i = 0; i <= row; i++) {
                        System.out.print("* ");
                        }
                    }
                    System.out.println();
                }
        }
    }
