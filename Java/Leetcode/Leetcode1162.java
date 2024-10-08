package com.company;

public class Leetcode1162 {
    public static void main(String[] args) {
        String[] a={"Soh","ail"};
        String[] b={"Soha","il"};
        System.out.println(equal(a,b));
    }


    static boolean equal(String[] a,String[] b){
        StringBuilder s1=new StringBuilder();
        StringBuilder s2=new StringBuilder();

        for (int i = 0; i < a.length; i++) {
            s1.append(a[i]);
        }

        for (int i = 0; i < b.length; i++) {
            s2.append(b[i]);
        }
        if(s1.toString().equals(s2.toString())){
            return true;
        }
        else{
            return false;
        }
    }
}
