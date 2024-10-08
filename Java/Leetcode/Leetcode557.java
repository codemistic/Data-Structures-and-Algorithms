package com.company;

public class Leetcode557 {
    public static void main(String[] args) {
        String s="Let's take LeetCode contest";
        String answer=reverseWords(s);
        System.out.println(answer);
    }

    public static String reverseWords(String s) {
        int space=0;
        StringBuilder sb=new StringBuilder(s);
        sb.append(" ");
        String updated="";
        while (sb.length()>1){
            space=sb.indexOf(" ");
            String str = reverse(sb.substring(0, space));
            updated=updated+" "+str;
            sb.delete(0,space+1);
        }
        return updated.trim();
    }

    public static String reverse(String s){
        StringBuilder sb=new StringBuilder(s);
        sb.reverse();
        return sb.toString();
    }
}
