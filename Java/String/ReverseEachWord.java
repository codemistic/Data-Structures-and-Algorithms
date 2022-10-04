// Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.

// Example:
// Input Sentence: "Hello, I am Aadil!"
// The expected output will print, ",olleH I ma !lidaA".



package String;
import java.util.Scanner;
public class ReverseEachWord {
    public static String reversed(String str) {
        String ans = "";
        int currentWordStart = 0;
        int i = 0;
        for (; i < str.length() ; i++) {
            if (str.charAt(i) == ' ') {
                int currentWordEnd = i - 1;
                String reverse = "";
                for (int j = currentWordStart; j <= currentWordEnd; j++) {
                    reverse = str.charAt(j) + reverse ;
                }
                ans += reverse + " ";
                currentWordStart = i + 1;
            }
        }
        int currentWordEnd = i - 1;
        String reverse = "";
        for (int j = currentWordStart; j <= currentWordEnd; j++) {
            reverse = str.charAt(j) + reverse;
        }
        ans += reverse;
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String ans = reversed(str);
        System.out.println(ans);
    }
}
