package com.company;

public class Leetcode1528 {
    public static void main(String[] args) {
        String s="codeleet";
        int[] arr={4,5,6,7,0,2,1,3};
        String answer=restoreString(s,arr);
        System.out.println(answer);
    }

    public static String restoreString(String s, int[] arr) {
        StringBuilder str=new StringBuilder();
        char[] charArray =new char[s.length()];
        for (int i = 0; i < s.length(); i++) {
            charArray[arr[i]]=s.charAt(i);
        }

        for (int i = 0; i < s.length(); i++) {
            str.append(charArray[i]);
        }
        return str.toString();
    }
}
