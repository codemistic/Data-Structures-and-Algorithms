//For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.


package String;
import java.util.*;
public class CheckPermutation {
    public static boolean checkPermutation(String str1 , String str2) {

        //To covert into character array.
        char [] c1= str1.toCharArray();
        char [] c2= str2.toCharArray();
        //Sort thr array.
        Arrays.sort(c1);
        Arrays.sort(c2);
        //return the value into string.
        str1=new String(c1);
        str2=new String(c2);
        //check wheter they are equal or not.
        return str1.equals(str2);

    }
    public static void main(String[] args) {
        String str1 = "abc";
        String str2 ="acb";
        boolean i = checkPermutation(str1, str2);
        System.out.println(i);
    }
}
