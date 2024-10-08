package com.company;

public class Leetcode344 {
    public static void main(String[] args) {
        char[] a={'a','b','c','d','e'};
        reverseString(a);
        System.out.println(a);
    }

    static void reverseString(char[] s) {
        int i=0;
        while (i<s.length/2){
            int endIndex=s.length-1-i;
            swap(s,i,endIndex);
            i++;
        }
    }

    static void swap(char[] s,int a, int b){
        char temp=s[a];
        s[a]=s[b];
        s[b]=temp;
    }
}
