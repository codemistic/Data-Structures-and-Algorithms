// For a given input string(str), write a function to print all the possible substrings.

package String;
import java.util.Scanner;
public class PrintAllSubstring {

    public static void substrings( String str) {
        for (int i = 0; i < str.length(); i++) {
            for (int j = i; j < str.length(); j++) {
                String substring = str.substring(i,j+1);
                System.out.print(substring +  " ");

            }

        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in);
        String str = sc.nextLine();
        substrings(str);
    }
}
