
//For a given string(str), remove all the consecutive duplicate characters.
package String;

public class remove_consecutivrs_Duplicaates {

    public static String remove(String str) {
        int n = str.length();
        String ans = "";
        for (int i = 0; i < n - 1; i++) {
            if (str.charAt(i) != str.charAt(i + 1)) {
                ans += str.charAt(i);
            }
        }

        ans = ans + str.charAt(n - 1);
        return ans;
    }

    public static void main(String[] args) {
        String str = "xxyyzxx";
        String ans = remove(str);
        System.out.println(ans);

    }
}
