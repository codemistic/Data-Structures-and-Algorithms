package com.company;

public class Leetcode168 {
    public static void main(String[] args) {
        int columnNumber=701;
        String answer=convertToTitle(columnNumber);
        System.out.println(answer);
    }

    public static String convertToTitle(int columnNumber) {
        int n=columnNumber,x=0,y=0;
        String columnTitle="";
        while (n>=1){
            x=n/26;

            if (x==0){
                y=n+64;
                columnTitle=columnTitle+(char)y;
                n=n/26;
            }

            if (x>=1 && x<=26){
                y=x+64;
                columnTitle=columnTitle+(char)y;
                break;
            }

            if (x>26){
                y=x%26;
                y=y+64;
                columnTitle=columnTitle+(char)y;
                n=n/26;
            }

        }
        columnTitle=columnTitle+(char)((columnNumber%26)+64);
        return columnTitle;
    }
}
