package com.company;

public class Leetcode2000 {
    public static void main(String[] args) {
        String s="abcd";
        char ch='z';
        System.out.println(reversePrefix(s,ch));
    }

    static String reversePrefix(String s,char ch){
        int a=s.indexOf(ch);
        StringBuilder str=new StringBuilder();
        for (int i = a; i >=0 ; i--) {
            str.append(s.charAt(i));
        }
        for (int i = a+1; i < s.length(); i++) {
            str.append(s.charAt(i));
        }
        return str.toString();
    }
}
