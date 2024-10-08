package com.company;

public class Leetcode1704 {
    public static void main(String[] args) {
        String s="Sohail";
        System.out.println(halvesAreAlike(s));
    }


    static boolean halvesAreAlike(String s) {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < (s.length() / 2); i++) {
            char ch = Character.toUpperCase(s.charAt(i));
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                c1++;
            }
        }
        for (int i = (s.length() / 2); i < s.length(); i++) {
            char ch = Character.toUpperCase(s.charAt(i));
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                c2++;
            }
        }

        if(c1==c2){
            return true;
        }
        else {
            return false;
        }
    }
}
