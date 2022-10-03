// For a given a string(str) and a character X, write a function to remove all the occurrences of X from the given string.
// The input string will remain unchanged if the given character(X) doesn't exist in the input string.


package String;

public class Remove_Character {
    public static String remove(String str , char ch) {
        String ans = "";
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) != ch) {
                ans += str.charAt(i);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        String str = "aabccbaa";
        char ch = 'a';
        String ans = remove(str , ch);
        System.out.println(ans);
    }
}
