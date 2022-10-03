package com.company;

public class Leetcode58 {
    public static void main(String[] args) {
        String s="   fly me   to   the moon  ";
        System.out.println(length(s));
    }

    static int length(String str){
        StringBuilder s=new StringBuilder(str.trim());
        int l=0;
        for (int i = s.length()-1; i >=0 ; i--) {
            if(Character.isWhitespace(s.charAt(i))){
                return l=(s.substring(i+1).length());
            }
        }
        return s.length();
    }
}