package com.company;

public class Leetcode1108 {
    public static void main(String[] args) {
        String address="255.0.154.25";
        System.out.println(defang(address));
    }


    static String defang(String add){
        StringBuilder str=new StringBuilder();
        for (int i = 0; i <add.length() ; i++) {
            if(add.charAt(i)=='.') {
                str.append("[.]");
//                str.append('.');
//                str.append(']');
            }
            else{
                str.append(add.charAt(i));
            }
        }
        return str.toString();
    }
}

