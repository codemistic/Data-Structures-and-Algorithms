//For a given a string(str), find and return the highest occurring character.

package String;

import java.util.Arrays;

public class Highest_Occuring_character {

    public static char highest(String str) {
        // Convert into character array.
        char[] ch = str.toCharArray();
        // Sort the array.
        Arrays.sort(ch);
        // Return into string.
        String str1 = new String(ch);
        int max = -1;
        char cha = ' ';
        for (int i = 0; i < str1.length(); i++) {
            int count = 1;
            if (str1.charAt(i) == str1.charAt(i + 1)) {
                count += 1;
            }
            if (count > max) {
                cha = str1.charAt(i);
            }

        }
        return cha;
    }

    public static void main(String[] args) {
        String str = "abdefgbabfba";
        char him = highest(str);
        System.out.println(him);
    }
}
