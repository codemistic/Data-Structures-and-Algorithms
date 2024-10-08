package com.company;

public class Leetcode20 {
    public static void main(String[] args) {
        String s=")){}[]";
        System.out.println(paranthesis(s));
    }

    static boolean paranthesis(String s){
        if(s.length()%2!=0){
            return false;
        }
        for (int i = 0; i <s.length(); i=i+2) {
            if (s.charAt(i)==')' || s.charAt(i)=='}' ||s.charAt(i)==']'){
                return false;
            }
                if((s.charAt(i)=='(' && s.charAt(i+1)!=')' )||(s.charAt(i)=='{'&& s.charAt(i+1)!='}' ||(s.charAt(i)=='[' && s.charAt(i+1)!=']' ))){
                    return false;
                }
            }
        return true;
        }
    }
