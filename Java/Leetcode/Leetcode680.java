package com.company;

public class Leetcode680 {
    public static void main(String[] args) {
        StringBuilder s=new StringBuilder("sohail");
        System.out.println(palindrome(s));
    }

    static boolean palindrome(StringBuilder s){
        boolean ans=palin(s);

        if(ans){
            return true;
        }

        for (int i = 0; i < s.length(); i++) {
            StringBuilder s2=new StringBuilder(s);
            s2.deleteCharAt(i);
            ans=palin(s2);
            if(ans){
                return true;
            }
        }
    return false;
    }


    static boolean palin(StringBuilder s) {
        StringBuilder s1 = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = Character.toLowerCase(s.charAt(i));
            if (ch >= 97 && ch <= 122 || ch >= 48 && ch <= 57) {
                s1.append(ch);
            }
        }

        StringBuilder s2 = new StringBuilder(s1);

        reverse(s2);

        return s1.toString().equals(s2.toString());
    }

    static void reverse(StringBuilder s){
        int start=0,end=s.length()-1;
        while(end>start){
            char temp;
            temp=s.charAt(start);
            s.setCharAt(start,s.charAt(end));
            s.setCharAt(end,temp);
            start++;
            end--;
        }
    }
}
