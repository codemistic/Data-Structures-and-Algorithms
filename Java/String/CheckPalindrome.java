//Check whether the string is palindrome or not.
//Return true if the string is palindrome else return false.

package String;
import java.util.Scanner;
public class CheckPalindrome {

    public static boolean check(String str) {
        String reversed = "";

        boolean ispal = false;
        for (int i = 0; i < str.length(); i++) {
            reversed = str.charAt(i) + reversed;
        }
       if (reversed.equals(str)) {
          ispal = true;
       }
        return ispal;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
         boolean check = check(str);
        System.out.println(check);
    }

}
