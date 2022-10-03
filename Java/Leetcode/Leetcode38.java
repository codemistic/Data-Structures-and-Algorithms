package com.company;

public class Leetcode38 {
    public static void main(String[] args) {
        int num=1;
        System.out.println(countAndSay(num));
    }

    public static String countAndSay(int n) {

        String str=Integer.toString(n);
        int count=1;
        String answer="";
        StringBuilder sb=new StringBuilder(str);

        while (sb.length()>0){
            char ch= sb.charAt(0);
            sb.deleteCharAt(0);

            for (int i = 0; i < sb.length(); i++) {
                if(ch==sb.charAt(i)){
                    count++;
                    sb.deleteCharAt(i);
                    i--;
                }
            }
            answer=answer+count+ch;
            count=1;
        }
        return answer;
    }
}