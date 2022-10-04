// Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.

package String;

public class ReverseStringWordwise {

    public static String reversewordwise(String str) {
        String ans = "";
        int currentstart = str.length() - 1;
        int i = str.length() - 1;
        for (; i >= 0; i--) {
            if (str.charAt(i) == ' ') {
                int currentend = i + 1;
                String sub;
                sub = str.substring(currentend, currentstart + 1);
                ans = ans + sub + " ";
                currentstart = i - 1;
            }
        }
        int currentend = i + 1;
        String sub;
        sub = str.substring(currentend, currentstart + 1);
        ans = ans + sub + " ";
        return ans;
    }

    public static void main(String[] args) {
        String str = "welcome to coding ninjas";
        String ans = reversewordwise(str);
        System.out.println(ans + " ");
    }
}
