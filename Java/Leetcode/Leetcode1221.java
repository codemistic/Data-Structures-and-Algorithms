package com.company;

public class Leetcode1221 {
    public static void main(String[] args) {
        String s="RLRRLLRLRL";
        int answer=balancedStringSplit(s);
        System.out.println(answer);
    }

    public static int balancedStringSplit(String s) {
        int c=0,counter=0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i)=='R'){
                c++;
            } else if (s.charAt(i)=='L'){
                c--;
            }
            if (c==0){
                counter++;
                c=0;
            }
        }
        return counter;
    }
}
