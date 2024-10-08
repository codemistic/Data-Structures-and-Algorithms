package com.company;

public class Leetcode2011 {
    public static void main(String[] args) {
        String[] arr={"--X","X++","X++"};
        int answer=finalValueAfterOperations(arr);
        System.out.println(answer);
    }

    public static int finalValueAfterOperations(String[] operations) {
        int count=0;
        for (int i = 0; i < operations.length; i++) {
            if (operations[i].charAt(1)==('+')){
                count++;
            } else {
                count--;
            }
        }
        return count;
    }
}
