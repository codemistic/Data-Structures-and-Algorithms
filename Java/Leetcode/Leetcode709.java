package com.company;

public class Leetcode709 {
    public static void main(String[] args) {
        String s="SoHail";
        System.out.println(lowerCase(s));
    }

    static String lowerCase(String s){
        StringBuilder str=new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)>=65 && s.charAt(i)<=90 ){
                str.append(Character.toLowerCase(s.charAt(i)));
            }
            else{
                str.append(s.charAt(i));
            }
        }
        return str.toString();
    }
}
