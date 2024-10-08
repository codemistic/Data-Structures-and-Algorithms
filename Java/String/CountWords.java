//Count number of word in the string

package String;
import java.util.Scanner;

public class CountWords {

    public static int countWords(String str ) {
        int count =  0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                count += 1;
            }
        }
        return count + 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        int n =  countWords(str);
        System.out.println(n);
    }
}
