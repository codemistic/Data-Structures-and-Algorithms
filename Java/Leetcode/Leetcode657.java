package com.company;

public class Leetcode657 {
    public static void main(String[] args) {
        String s="LLUDRR";
        System.out.println(robot(s));
    }


    static boolean robot(String s){
        int l=0,r=0,u=0,d=0;
        for (int i = 0; i < s.length(); i++) {
            char ch=s.charAt(i);
            if(ch=='L' || ch=='l'){
                l++;
            }
            if(ch=='R' ||ch=='r' ){
                r++;
            }
            if(ch=='U' || ch=='u'){
                u++;
            }
            if(ch=='D' ||ch=='d' ){
                d++;
            }
        }

        if(l==r && u==d){
            return true;
        }
        else{
            return false;
        }
    }
}
