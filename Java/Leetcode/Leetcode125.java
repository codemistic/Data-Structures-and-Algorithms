package com.company;

public class Leetcode125 {
    public static void main(String[] args) {
        String s="OP";
        System.out.println(palin(s));
    }

    static boolean palin(String s) {
        StringBuilder s1 = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = Character.toLowerCase(s.charAt(i));
            if (ch >= 97 && ch <= 122 || ch >= 48 && ch <= 57) {
                s1.append(ch);
            }
        }

        StringBuilder s2 = new StringBuilder(s1);

        reverse(s2);

        if (s1.toString().equals(s2.toString())) {
            return true;
        } else {
            return false;
        }
    }

    static void reverse(StringBuilder s){
        int start=0,end=s.length()-1;
        while(end>start){
            swap(s,start,end);
            start++;
            end--;
        }
    }

    static void swap(StringBuilder s,int a,int b){
        char temp;
        temp=s.charAt(a);
        s.setCharAt(a,s.charAt(b));
        s.setCharAt(b,temp);
    }
}
