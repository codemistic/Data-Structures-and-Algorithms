package com.company;

public class Leetcode2114 {
    public static void main(String[] args) {

    }

    public static int mostWordsFound(String[] sentences) {
        int max=0;
        for (int i = 0; i < sentences.length; i++) {
            String[] arr=sentences[i].split(" ");
            if(arr.length>max){
            max=arr.length;
            }
        }
        return max;
    }
}
