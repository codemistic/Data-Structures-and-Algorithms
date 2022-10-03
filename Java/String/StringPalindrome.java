import java.util.Scanner;
/*
* String is said to be a palindrome if the reverse of the string is exactly same as the given string. 
  */

public class StringPalindrome {
    
    public static void main(String[] args) {
        
        System.out.print("Enter a string: ");
        Scanner in=new Scanner(System.in);
        String str=in.next();
        System.out.println(ispali(str));

    }
    static String ispali(String str){
        str=str.toLowerCase();
        for (int i = 0; i <str.length()/2 ; i++) {
            char start=str.charAt(i);
            char end=str.charAt(str.length()-1-i);
            if(start!=end){
                return "It is not a palindrome";
            }
        }
        return "It is a palindrome";
    }
}
